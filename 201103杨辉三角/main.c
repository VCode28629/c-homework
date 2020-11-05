/*****************************************************************************
 * project name: 杨辉三角                                                     *
 * filename: main.c                                                          *
 * author: VCode                                                             *
 * create time: 2020/11/03                                                   *
 * last change time: 2020/11/05                                              *
 * License: GPL-3.0                                                          *
 *                                                                           *
 * Notice: This code is open source at                                       *
 *                 https://github.com/VCode28629/c-homework                  *
 * with GPL-3.0. Permissions of this strong copyleft license are conditioned *
 * on making available complete source code of licensed works and            *
 * modifications, which include larger works using a licensed work, under    *
 * the same license. Copyright and license notices must be preserved.        *
 * Contributors provide an express grant of patent rights.                   *
 *****************************************************************************/


#include<stdio.h>
#include<stdlib.h>

const int ratio = 4;

typedef struct pair {
    int first;
    int second;
} pair;

int cmp(pair a, pair b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

typedef struct node {
    int size;
    pair id;
    int key;
    struct node *left;
    struct node *right;
} node;

node *newNode(int size, pair id, int key, node *left, node *right) {
    node *res = (node*)malloc(sizeof(node));
    res->size = size;
    res->id = id;
    res->key = key;
    res->left = left;
    res->right = right;
    return res;
}

node *merge(node *a, node *b) {
    return newNode(a->size + b->size, b->id, b->key, a, b);
}

void maintain(node *now) {
    node *temp;
    if(now->size == 1) return;
    if(now->left->size * ratio < now->right->size) {
        now->left = merge(now->left, now->right->left);
        temp = now->right;
        now->right = now->right->right;
        free(temp);
    } else if(now->right->size * ratio < now->left->size) {
        now->right = merge(now->left->right, now->right);
        temp = now->left;
        now->left = now->left->left;
        free(temp);
    }
}

void pushup(node *now) {
    if(now->left != NULL) {
        now->size = now->left->size + now->right->size;
        now->id = now->right->id;
        now->key = now->right->key;
    }
}

node *insert(node *now, pair id, int key) {
    if(now == NULL) {
        return newNode(1, id, key, NULL, NULL);
    }
    if(now->size == 1) {
        if(cmp(id, now->id)) {
            now->left = newNode(1, id, key, NULL, NULL);
            now->right = newNode(1, now->id, now->key, NULL, NULL);
        } else if(cmp(now->id, id)) {
            now->left = newNode(1, now->id, now->key, NULL, NULL);
            now->right = newNode(1, id, key, NULL, NULL);
        } else {
            now->key = key;
        }
    } else {
        insert(cmp(now->left->id, id) ? now->right : now->left, id, key);
    }
    pushup(now);
    maintain(now);
    return now;
}

int find(node *now, pair id) {
    if(now == NULL) return -1;
    while(now->size != 1) {
        if(cmp(now->left->id, id)) {
            now = now->right;
        } else {
            now = now->left;
        }
    }
    if(cmp(id, now->id) || cmp(now->id, id)) return -1;
    return now->key;
}

node *root;

pair make_pair(int first, int second) {
    pair res;
    res.first = first;
    res.second = second;
    return res;
}

int get_value(int row, int col) {
    pair id = make_pair(row, col);
    int mem = find(root, id);
    if(mem != -1) return mem;
    if(col == 0 || row == col) {
        mem = 1;
    } else {
        mem = get_value(row - 1, col) + get_value(row - 1, col - 1);
    }
    root = insert(root, id, mem);
    return mem;
}

int main() {
    int i, j;
    for(i = 0; i < 8; ++i) {
        for(j = 0; j <= i; ++j) {
            printf("%d ", get_value(i, j));
        }
        putchar('\n');
    }
    return 0;
}
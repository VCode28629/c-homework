/*****************************************************************************
 * project name: 找水仙花数                                                   *
 * filename: main.c                                                          *
 * author: VCode                                                             *
 * create time: 2020/10/27                                                   *
 * last change time: 2020/10/27                                              *
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

int fpow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res *= a;
        b >>= 1;
        a *= a;
    }
    return res;
}

int check(int key, int n) {
    int temp = key;
    while(temp) {
        key -= fpow(temp % 10, n);
        temp /= 10;
    }
    return key == 0;
}

int main() {
    int len;
    int l, r;
    for(len = 1; len <= 6; ++len) {
        l = fpow(10, len - 1);
        r = fpow(10, len);
        for(; l < r; ++l) {
            if(check(l, len)) printf("%d\n", l);
        }
    }
    return 0;
}

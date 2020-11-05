/*****************************************************************************
 * project name: 再找水仙花数                                                 *
 * filename: main.c                                                          *
 * author: VCode                                                             *
 * create time: 2020/11/03                                                   *
 * last change time: 2020/11/03                                              *
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

int no_of_digits(int x) {
    int res = 0;
    while(x) {
        res += 1;
        x /= 10;
    }
    return res;
}

int power(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res *= x;
        y >>= 1;
        x *= x;
    }
    return res;
}

int is_narciss(int x) {
    int n =  no_of_digits(x);
    int temp = x;
    while(temp) {
        x -= power(temp % 10, n);
        temp /= 10;
    }
    return x == 0;
}

int main() {
    int i;
    for(i = 0; i < 1000000; ++i) {
        if(is_narciss(i)) printf("%d\n", i);
    }
    return 0;
}

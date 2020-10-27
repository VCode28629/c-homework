/*****************************************************************************
 * project name: 再求身份证校验码                                             *
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

int getWi(int id) {
    if(id < 0) return -1;
    if(id >= 18) return -1;
    int w[18] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2, 1};
    return w[id];
}

int main() {
    int sum = 0;
    int res;
    int i;
    printf("请输入身份证号前17位：");
    for(i = 0; i < 17; ++i) {
        int temp;
        scanf("%1d", &temp);
        sum += temp * getWi(i);
    }
    sum %= 11;
    res = (12 - sum + 11) % 11;
    printf("该身份证的校验码为：%c\n", res == 10 ? 'X' : res + '0');
    return 0;
}

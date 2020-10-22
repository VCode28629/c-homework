/*****************************************************************************
 * project name: 由日期求星期几                                               *
 * filename: main.c                                                          *
 * author: VCode                                                             *
 * create time: 2020/10/22                                                   *
 * last change time: 2020/10/22                                              *
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

int main() {
    int year, month, date;
    scanf("%d%d%d", &year, &month, &date);
    if(year < 1600) {
        puts("Unknown weekday");
        return 0;
    }
    if(month == 1 || month == 2) {
        year -= 1;
        month += 12;
    }
    int ans = (date + 26 * (month + 1) / 10 + year + year / 4 + 6 * (year / 100) + year / 400) % 7;
    switch(ans) {
        case 0:
            puts("Saturday");
            break;
        case 1:
            puts("Sunday");
            break;
        case 2:
            puts("Monday");
            break;
        case 3:
            puts("Tuesday");
            break;
        case 4:
            puts("Wednesday");
            break;
        case 5:
            puts("Thursday");
            break;
        case 6:
            puts("Friday");
            break;
    }
    // printf("%d\n", ans);
    return 0;
}

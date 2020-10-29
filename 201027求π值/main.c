/*****************************************************************************
 * project name: 求π值                                                       *
 * filename: main.c                                                          *
 * author: VCode                                                             *
 * create time: 2020/10/27                                                   *
 * last change time: 2020/10/29                                              *
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
#include<math.h>

double inscribed(double last) {
    // parameter last is the side length for a regular n edge inside the circle
    // return the side length for a regular 2n edge inside the circle
    return sqrt((1 - sqrt(1 - last * last)) / 2);
}

double circumscribed(double last) {
    // parameter last is the side length for a regular n edge outside the circle
    // return the side length for a regular 2n edge outside the circle
    return (sqrt(1 + last * last) - 1) / last ;
}

int main() {
    int n = 6;
    double a = 0.5;
    double b = 1 / sqrt(3);
    while(a < b && (n << 1) > 0) { // it will stop either a >= b or (n << 1) <= 0(meaning looped too many times)
        // printf("%lf %lf\n", a * n, b * n);
        a = inscribed(a);
        b = circumscribed(b);
        n <<= 1;
    }
    printf("%lf\n", a * n);
}

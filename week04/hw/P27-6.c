#include <stdio.h>

int main() {
    int int_n = 0;
    unsigned int u_int_n = 0;
    // int float_n = 0;
    long long double_n = 0;

    while (1) {
        int_n <<= 1;
        int_n += 1;
        if (int_n == -1) break;
        printf("%d\n", int_n);
    }
    printf("-- int 最大值如上 --\n");
    printf("-- int 最小值: %d\n", ~(int_n & 0x7fffffff));

    while (1) {
        u_int_n <<= 1;
        u_int_n += 1;
        printf("%u\n", u_int_n);
        if ((int)u_int_n == -1) break;
    }
    printf("-- unsigned int 最大值如上 --\n");
    printf("-- unsigned int 最小值: %d--\n\n", 0);

    float float_n = -8.25;
    char *tmp = (char *)&float_n;
    *tmp = 0xff;
    *(tmp + 1) = 0xff;
    *(tmp + 2) = 0x7f;
    *(tmp + 3) = 0x7f; //0 11111110 1111111 1111 1111 1111 1111

    printf("\n&f = %x", &float_n);
	printf("\n最大float： f = %f", float_n);
    printf("\n最小float： f = %f", -float_n);

    *tmp = 0x01;
    *(tmp + 1) = 0x00;
    *(tmp + 2) = 0x00;
    *(tmp + 3) = 0x00;

    printf("\n&f = %x", &float_n);
	printf("\n最小float正数： f = %e", float_n);
    printf("\n最大float负数： f = %e\n", -float_n);

    return 0;
}

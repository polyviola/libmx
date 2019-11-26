#include "libmx.h"

static int check_number(int *n) {
    if (*n == -2147483648) {
        write(1, "-2147483648", 11);
        return 0;
    }
    if (*n == 0) {
        write(1, "0", 1);
        return 0;
    }
    if (*n < 0) {
        write (1, "-", 1);
        *n *= -1;
    }
    return 1;
}

void mx_printint(int n) {
    int size = 0;
    int i = 0;
    char mass[10];

    if (check_number(&n)) {
        while (n) {
            mass[i++] = (n % 10) + 48;
            n /= 10;
            size++;
        }
        for (int i = 0; i < size; i++) {
        write(1, &mass[size - i - 1], 1);
        }
    }
}

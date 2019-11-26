#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *res = NULL;
    unsigned int size  = 0;
    unsigned long copydel = nbr;
    unsigned long copyost = nbr;
    
    while(copyost != 0) {
        copyost /= 16;
        size++;
    }
    copyost  = nbr;
    char hexa[size];
    for (unsigned int i = 0; i < size; i++) {
        copyost = copydel % 16;
        copydel /= 16;
        if (copyost < 9) 
            hexa[size - i - 1] = copyost + 48;
        else 
            hexa[size - i - 1] = copyost + 87;
    }
    res = mx_strnew(size);
    for (unsigned int i = 0; i < size; i++) {
        res[i] = hexa[i];
    }
    return res;
}

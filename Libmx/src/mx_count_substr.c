#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int counter = 0;
    int temp = 0;
    
    if (str != NULL && sub != NULL) {
        for (int i = 0; str[i] != '\0'; i++) {
            temp = mx_get_substr_index(&str[i], sub);
            if (temp >= 0) {
                counter++;
                i += temp;
            }
            temp = 0;
        }
        return counter;
    }
    else 
        return -1;
}

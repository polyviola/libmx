#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    int newlen = 0;
    int i = 0;
    int counter = 0;
    if (sub && str && replace) {
        counter = mx_count_substr(str, sub); 
        newlen = mx_strlen(str) - counter * mx_strlen(sub) + counter * mx_strlen(replace)  + 1;
        char *newstr = mx_strnew(newlen);
        for (int k = 0; str[k] != '\0'; k++) {
            char *ukaz = mx_strstr(&str[k], sub);
            if (ukaz != NULL) {
            while (&str[k] != ukaz) 
                newstr[i++] = str[k++];
            mx_strcat(&newstr[i], replace);
            i += mx_strlen(replace);
            k++;
            }
            else if (i == k && str[k + 1] != '\0') {
                while (k < newlen) {
                    newstr[i++] = str[k++];
                }
                newstr[i] = str[k];
            }
        }
        return newstr;
    }
    else 
        return NULL;
}

#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int strlen = str ? mx_strlen(str) : 0;
    int entry = 0;
    
    if (str == NULL || sub == NULL) 
        return -2;
    for (int i = 0, j = 0; i <= strlen; i++) {
        while (str[i] != sub[j]) {
            if (str[i + 1] == '\0') 
                return -1;
            i++;
        }
        if (str[i] == sub[0]) {
                entry = i;
        }
        while(str[i++] == sub[j++]) {
                if (sub[j + 1] == '\0')
                return entry;
        }
        if (str[i] == '\0')
            return -1;
        i--;
        entry = 0;
        j = 0;
    }
    return entry;
    }

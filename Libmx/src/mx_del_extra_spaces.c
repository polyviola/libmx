#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *newmass = NULL;
    char *output = NULL;
    int len = 0;
    
    if (str) {
        newmass = mx_strtrim(str);
        for (int i = 0; newmass[i] != '\0'; i++) {
            while ((mx_isspace(newmass[i]) == 0 || (mx_isspace(newmass[i]) == 1  && mx_isspace(newmass[i + 1]) == 0)) && newmass[i]) {
                len++;
                i++;
            }
        }
        output = mx_strnew(len + 1);
        for (int i = 0, j = 0; newmass[i] != '\0'; i++) {
            if (mx_isspace(newmass[i]) == 0 || (mx_isspace(newmass[i]) == 1 && mx_isspace(newmass[i + 1]) == 0)) {
                if (mx_isspace(newmass[i]) == 1) {
                    output[j] = ' ';
                }
                if (mx_isspace(newmass[i]) == 0) {
                output[j] = newmass[i];
                }
                j++;
            }
        }
        return output;
    }
    return NULL;
}

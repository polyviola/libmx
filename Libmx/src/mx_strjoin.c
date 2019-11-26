#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    int i = 0;
    int s1len = s1 ? mx_strlen(s1) : 0;
    int s2len = s2 ? mx_strlen(s2) : 0;
    
    if (s1 && s2) {
        char *newstr = NULL;
        newstr = mx_strnew(s1len + s2len);
        if (i <= s1len + s2len) {
        mx_strcpy(&newstr[i], s1);
        i += s1len;
        }
        mx_strcpy(&newstr[i], s2);
        return newstr;
    }
    else if (s2) 
        return mx_strdup(s2);
    else if (s1) 
        return mx_strdup(s1);
    else
        return NULL;
}

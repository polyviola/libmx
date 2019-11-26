#include "libmx.h"

static int get_len(const char *file) {
    int ofi = open(file, O_RDONLY);
    int size = 0;
    char buf;
    
    if (ofi) {
        while (read(ofi, &buf, 1)) {
            size++;
        }
    }
    close(ofi);
    return size;
}
char *mx_file_to_str(const char *file) {
    char buff;
    int ofi = open(file, O_RDONLY);
    int len = get_len(file);
    
    if (ofi && len) {
        char *mass = mx_strnew(len);
        for (int i = 0; i < len; i++) {
            read(ofi, &buff, 1);
            mass[i] = buff;
        }
        close(ofi);
        return mass;
    }
    else 
        return NULL;
}

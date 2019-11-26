#include "libmx.h"

static int sort(char **arr, int left, int right) {
    char *zapas;
    int i = left;
    int j = right;
    int shifts = 0;
    char *pivot = arr[left + (right - left) / 2];

    while (i <= j) {
        while (mx_strlen(arr[i]) < mx_strlen(pivot))
        i++;
        while(mx_strlen(arr[j]) > mx_strlen(pivot)) 
        j--;
        if (i <= j) {
            if (mx_strlen(arr[i]) > mx_strlen(arr[j])) {
                zapas = arr[i];
                arr[i] = arr[j];
                arr[j] = zapas;
                shifts++;
            }
            i++;
            j--;
        }
    }
    return shifts += (i < right ? sort(arr, i, right) : 0) + (left < j ? sort(arr, left, j) : 0);
}

int mx_quicksort(char **arr, int left, int right) {
    return arr ? sort(arr, left, right) : -1;
}

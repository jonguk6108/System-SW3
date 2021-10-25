#include "my_sort.h"

void quick_sort (int *array, int size) {

    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size - i; j++) {
            
            if (*(array + j) > *(array + j + 1)) {
                change(array, j, j+1);
            }
        }
    }

    return;
}

void change (int *array, int first_idx, int second_idx) {
    int temp_change = *(array + first_idx);

    *(array + first_idx) = *(array + second_idx);
    *(array + second_idx) = temp_change;

    return;
}

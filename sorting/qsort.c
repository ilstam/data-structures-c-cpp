#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

void print_int_array(int *array, int size)
{
    for (int *p = array; p < array + size; p++) {
        printf("%d\n", *p);
    }

}

bool compare_int_arrays(int *a1, int a1_size, int *a2, int a2_size)
{
    if (a1_size != a2_size) {
        return false;
    }

    int *p1 = a1, *p2 = a2;

    for (; p1 < a1 + a1_size; p1++, p2++) {
        if (*p1 != *p2) {
            return false;
        }
    }

    return true;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *array, int left, int right)
{
    int pivot = array[left];
    int i = left+1, j = left;

    for (; i <= right; i++) {
        if (array[i] <= pivot) {
            j++;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[left], &array[j]);

    return j;
}

// average runnning time: O(nlogn)
// worst case running time: O(n^2)
void randomized_qsort(int *array, int left, int right)
{
    if (left >= right) {
        return;
    }

    // pick a random number between left and right
    int random = (rand() % (right - left + 1)) + left;
    swap(&array[left], &array[random]);

    int m = partition(array, left, right);
    randomized_qsort(array, left, m-1);
    randomized_qsort(array, m+1, right);
}

int main(void)
{
    srand(time(NULL));

    int array[] = {4, 2, 19, 7, 34, 56};
    randomized_qsort(array, 0, ARRAY_SIZE(array) - 1);
    assert(compare_int_arrays(array,
                          ARRAY_SIZE(array),
                          (int []) {2, 4, 7, 19, 34, 56},
                          ARRAY_SIZE(array)));

    int array2[] = {3, 2, 1};
    randomized_qsort(array2, 0, ARRAY_SIZE(array2) - 1);
    assert(compare_int_arrays(array2,
                          ARRAY_SIZE(array2),
                          (int []) {1, 2, 3},
                          ARRAY_SIZE(array2)));

    return 0;
}

#include <stdio.h>

#define ASSERT(expected, actual)                                               \
    ++total_tests;                                                             \
    if (expected != actual) {                                                  \
        ++failed_tests;                                                        \
        printf("\033[1;31m");                                                  \
        printf("Test failed. Expected %d but got %d.\n%s(%d)\n\n", expected,   \
               actual, __FILE__, __LINE__);                                    \
        printf("\033[0m");                                                     \
    } else {                                                                   \
        printf("\033[1;32m");                                                  \
        printf("Test passed.\n\n");                                            \
        printf("\033[0m");                                                     \
    }

int total_tests, failed_tests;

int binary_search_iterative(int arr[], int size, int target) {
    int start, middle, end;
    start = 0;
    end = size - 1;
    while (start <= end) {
        middle = (int)(start + end) / 2;
        if (target == arr[middle]) {
            return middle;
        } else if (target < arr[middle]) {
            end = middle - 1;

        } else {
            start = middle + 1;
        }
    }
    return -1;
}

int binary_search_iterative_2(int arr[], int size, int target) {
    int start = -1;
    int end = size;
    int middle;
    while (end - start > 1) {
        middle = start + (end - start) / 2;
        if (target < arr[middle]) {
            end = middle;
        } else {
            start = middle;
        }
    }
    return start;
}

int binary_search_recursive(const int arr[], int start, int end, int target) {
    while (start <= end) {
        int middle = (int)(start + end) / 2;
        if (target == arr[middle]) {
            return middle;
        } else if (target < arr[middle]) {
            return binary_search_recursive(arr, start, middle - 1, target);
        } else {
            return binary_search_recursive(arr, middle + 1, end, target);
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 4, 10, 12, 24, 28, 37, 39, 41, 43, 44, 57, 73};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target1 = 2;
    int target2 = 12;
    int target3 = 28;
    int target4 = 37;
    int target5 = 41;
    int target6 = 57;

    // Iterative
    printf("Iterative\n\n");
    int result_iterative;
    result_iterative = binary_search_iterative(arr, size, target1);
    ASSERT(target1, arr[result_iterative]);
    result_iterative = binary_search_iterative(arr, size, target2);
    ASSERT(target2, arr[result_iterative]);
    result_iterative = binary_search_iterative(arr, size, target3);
    ASSERT(target3, arr[result_iterative]);
    result_iterative = binary_search_iterative(arr, size, target4);
    ASSERT(target4, arr[result_iterative]);
    result_iterative = binary_search_iterative(arr, size, target5);
    ASSERT(target5, arr[result_iterative]);
    result_iterative = binary_search_iterative(arr, size, target6);
    ASSERT(target6, arr[result_iterative]);

    // Iterative2
    printf("Iterative2\n\n");
    int result_iterative2;
    result_iterative2 = binary_search_iterative_2(arr, size, target1);
    ASSERT(target1, arr[result_iterative2]);
    result_iterative2 = binary_search_iterative_2(arr, size, target2);
    ASSERT(target2, arr[result_iterative2]);
    result_iterative2 = binary_search_iterative_2(arr, size, target3);
    ASSERT(target3, arr[result_iterative2]);
    result_iterative2 = binary_search_iterative_2(arr, size, target4);
    ASSERT(target4, arr[result_iterative2]);
    result_iterative2 = binary_search_iterative_2(arr, size, target5);
    ASSERT(target5, arr[result_iterative2]);
    result_iterative2 = binary_search_iterative_2(arr, size, target6);
    ASSERT(target6, arr[result_iterative2]);

    // Recursive
    printf("Recursive\n\n");
    int result_recursive;
    result_recursive = binary_search_recursive(arr, 0, size - 1, target1);
    ASSERT(target1, arr[result_recursive]);
    result_recursive = binary_search_recursive(arr, 0, size - 1, target2);
    ASSERT(target2, arr[result_recursive]);
    result_recursive = binary_search_recursive(arr, 0, size - 1, target3);
    ASSERT(target3, arr[result_recursive]);
    result_recursive = binary_search_recursive(arr, 0, size - 1, target4);
    ASSERT(target4, arr[result_recursive]);
    result_recursive = binary_search_recursive(arr, 0, size - 1, target5);
    ASSERT(target5, arr[result_recursive]);
    result_recursive = binary_search_recursive(arr, 0, size - 1, target6);
    ASSERT(target6, arr[result_recursive]);

    return 0;
}

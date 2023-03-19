#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
    int l = 0;
    int r = length - 1;

    while(l <= r) {
        int mid = floor((l + r) / 2);

        if(arr[mid] < value) {
            l = mid + 1;
        } else if(arr[mid] > value) {
            r = mid - 1;
        } else {
            return &arr[mid];
        }
    }

    return NULL;
}

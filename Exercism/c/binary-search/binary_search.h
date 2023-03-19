#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>
#include <math.h>
#include <stdio.h>

/**
 * @brief Binary search algorithm.
 * 
 * @param value Value to be found.
 * @param arr Array to search in.
 * @param length Length of the array.
 * @return const int* Reference to arrays index if value was found or NULL if not.
 */
const int *binary_search(int value, const int *arr, size_t length);

#endif

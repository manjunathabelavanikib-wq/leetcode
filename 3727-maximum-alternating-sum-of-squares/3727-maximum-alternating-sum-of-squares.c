
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long x = *(const int *)a;
    long long y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

long long maxAlternatingSum(int* nums, int numsSize) {
    long long *squares = malloc(numsSize * sizeof(long long));

    if (squares == NULL) {
        return 0;
    }

    // Calculate the square of each number
    for (int i = 0; i < numsSize; i++) {
        squares[i] = (long long)nums[i] * nums[i];
    }

    // Sort squares in ascending order
    qsort(squares, numsSize, sizeof(long long), compare);

    long long score = 0;

    // Subtract the smaller half and add the larger half
    int half = numsSize / 2;

    for (int i = 0; i < half; i++) {
        score -= squares[i];
    }

    for (int i = half; i < numsSize; i++) {
        score += squares[i];
    }

    free(squares);

    return score;
}


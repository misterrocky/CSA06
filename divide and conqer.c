#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair result, left, right, mid;
    int midIndex;

    // Base case: If the list has only one element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // If the list has two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // If the list has more than two elements, divide the list and recursively find min and max
    midIndex = (low + high) / 2;
    left = findMinMax(arr, low, midIndex);
    right = findMinMax(arr, midIndex + 1, high);

    // Merge the results
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int arr[] = {3, 1, 8, 4, 6, 2, 10, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Pair result = findMinMax(arr, 0, n - 1);

    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);

    return 0;
}

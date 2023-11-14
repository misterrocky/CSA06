#include <stdio.h>

#define MAX 10

int x[MAX];
int w[MAX];
int n, targetSum;

void sumOfSubsets(int s, int k, int r) {
    x[k] = 1;

    if (s + w[k] == targetSum) {
        printf("Subset: ");
        for (int i = 0; i <= k; i++) {
            if (x[i] == 1) {
                printf("%d ", w[i]);
            }
        }
        printf("\n");
    } else if (s + w[k] + w[k + 1] <= targetSum) {
        sumOfSubsets(s + w[k], k + 1, r - w[k]);
    }

    if ((s + r - w[k] >= targetSum) && (s + w[k + 1] <= targetSum)) {
        x[k] = 0;
        sumOfSubsets(s, k + 1, r - w[k]);
    }
}

int main() {
    int totalWeight = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        totalWeight += w[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets with sum equal to %d are:\n", targetSum);
    sumOfSubsets(0, 0, totalWeight);

    return 0;
}

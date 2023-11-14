#include <stdio.h>

#define MAX_ITEMS 10
#define MAX_CONTAINERS 10

int items[MAX_ITEMS];
int containers[MAX_CONTAINERS];

int n, m; // n is the number of items, m is the number of containers

void loadContainers(int itemIndex) {
    for (int i = 0; i < m; i++) {
        if (containers[i] >= items[itemIndex]) {
            containers[i] -= items[itemIndex];

            printf("Item %d fits into Container %d\n", itemIndex + 1, i + 1);

            if (itemIndex + 1 < n) {
                loadContainers(itemIndex + 1);
            } else {
                printf("All items loaded successfully.\n");
            }

            containers[i] += items[itemIndex]; // backtrack
        }
    }
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the sizes of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }

    printf("Enter the number of containers: ");
    scanf("%d", &m);

    printf("Enter the capacities of containers:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &containers[i]);
    }

    loadContainers(0);

    return 0;
}

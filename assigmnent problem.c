#include <stdio.h>
#include <limits.h>

#define N 4

int costMatrix[N][N] = {
    {4, 6, 7, 8},
    {7, 3, 4, 9},
    {5, 8, 7, 4},
    {7, 2, 8, 6}
};

int minCost = INT_MAX;

int assigned[N];

void printAssignment(int assignment[N]) {
    printf("Assigned tasks:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Task %d\n", i + 1, assignment[i] + 1);
    }
    printf("\n");
}

void updateMinCost(int assignment[N]) {
    int totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }

    if (totalCost < minCost) {
        minCost = totalCost;
        for (int i = 0; i < N; i++) {
            assigned[i] = assignment[i];
        }
    }
}

void branchAndBound(int costMatrix[N][N], int assignment[N], int row, int cost) {
    if (row == N) {
        updateMinCost(assignment);
        return;
    }

    for (int j = 0; j < N; j++) {
        if (!assignment[j]) {
            assignment[j] = row;
            branchAndBound(costMatrix, assignment, row + 1, cost + costMatrix[row][j]);
            assignment[j] = -1; // backtrack
        }
    }
}

int main() {
    int assignment[N];

    for (int i = 0; i < N; i++) {
        assignment[i] = -1;
    }

    branchAndBound(costMatrix, assignment, 0, 0);

    printf("Minimum Assignment Cost: %d\n", minCost);
    printAssignment(assigned);

    return 0;
}
#include <stdio.h>
#include <limits.h>

#define N 4

int costMatrix[N][N] = {
    {4, 6, 7, 8},
    {7, 3, 4, 9},
    {5, 8, 7, 4},
    {7, 2, 8, 6}
};

int minCost = INT_MAX;

int assigned[N];

void printAssignment(int assignment[N]) {
    printf("Assigned tasks:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Task %d\n", i + 1, assignment[i] + 1);
    }
    printf("\n");
}

void updateMinCost(int assignment[N]) {
    int totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }

    if (totalCost < minCost) {
        minCost = totalCost;
        for (int i = 0; i < N; i++) {
            assigned[i] = assignment[i];
        }
    }
}

void branchAndBound(int costMatrix[N][N], int assignment[N], int row, int cost) {
    if (row == N) {
        updateMinCost(assignment);
        return;
    }

    for (int j = 0; j < N; j++) {
        if (!assignment[j]) {
            assignment[j] = row;
            branchAndBound(costMatrix, assignment, row + 1, cost + costMatrix[row][j]);
            assignment[j] = -1; // backtrack
        }
    }
}

int main() {
    int assignment[N];

    for (int i = 0; i < N; i++) {
        assignment[i] = -1;
    }

    branchAndBound(costMatrix, assignment, 0, 0);

    printf("Minimum Assignment Cost: %d\n", minCost);
    printAssignment(assigned);

    return 0;
}

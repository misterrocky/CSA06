#include <stdio.h>

#define V 4

void printSolution(int color[]) {
    printf("Vertex colors:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d -> Color %d\n", i + 1, color[i]);
    printf("\n");
}

// Check if it is safe to color the vertex v with color c
int isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

// Recursive function to solve graph coloring problem
int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V)
        return 1;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return 1;

            color[v] = 0;
        }
    }

    return 0;
}

// Main function to solve graph coloring problem
void graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0) == 0) {
        printf("Solution does not exist.\n");
        return;
    }

    printSolution(color);
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors

    printf("Graph Coloring with %d colors:\n", m);
    graphColoring(graph, m);

    return 0;
}
#include <stdio.h>

#define V 4

void printSolution(int color[]) {
    printf("Vertex colors:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d -> Color %d\n", i + 1, color[i]);
    printf("\n");
}

// Check if it is safe to color the vertex v with color c
int isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

// Recursive function to solve graph coloring problem
int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V)
        return 1;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return 1;

            color[v] = 0;
        }
    }

    return 0;
}

// Main function to solve graph coloring problem
void graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0) == 0) {
        printf("Solution does not exist.\n");
        return;
    }

    printSolution(color);
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors

    printf("Graph Coloring with %d colors:\n", m);
    graphColoring(graph, m);

    return 0;
}

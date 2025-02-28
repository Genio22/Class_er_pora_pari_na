#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_VALUES 5
int n_values[N_VALUES] = {1000, 2000, 3000, 4000, 5000};

// Function to generate a random adjacency matrix for an undirected graph
void generateGraph(int **graph, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int edge = rand() % 2; // Randomly 0 or 1
            graph[i][j] = edge;
            graph[j][i] = edge;
        }
        graph[i][i] = 0; // No self-loops
    }
}

// Function to count edges and verify Handshaking Theorem
void analyzeGraph(int **graph, int n) {
    int edgeCount = 0;
    int *degrees = (int *)calloc(n, sizeof(int));
    clock_t start, end;
    
    start = clock(); // Start timing computation
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] == 1) {
                edgeCount++;
                degrees[i]++;
                degrees[j]++;
            }
        }
    }
    
    int degreeSum = 0;
    for (int i = 0; i < n; i++) {
        degreeSum += degrees[i];
    }
    
    end = clock(); // End timing computation
    double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Convert to ms
    
    printf("n = %d\n", n);
    printf("Edges: %d\n", edgeCount);
    printf("Sum of Degrees: %d\n", degreeSum);
    printf("Handshaking Theorem holds: %s\n", (degreeSum == 2 * edgeCount) ? "Yes" : "No");
    printf("Computation Time: %.2f ms\n", time_spent);
    printf("---------------------------------\n");
    
    free(degrees);
}

int main() {
    srand(time(NULL)); // Seed random number generator
    
    for (int idx = 0; idx < N_VALUES; idx++) {
        int n = n_values[idx];
        
        // Allocate adjacency matrix dynamically
        int **graph = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            graph[i] = (int *)malloc(n * sizeof(int));
        }
        
        generateGraph(graph, n);
        analyzeGraph(graph, n);
        
        // Free allocated memory
        for (int i = 0; i < n; i++) {
            free(graph[i]);
        }
        free(graph);
    }
    
    return 0;
}

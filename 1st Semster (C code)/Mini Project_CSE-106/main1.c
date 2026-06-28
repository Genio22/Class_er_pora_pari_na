#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void generate_graph(int n, int *matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int val = rand() % 2;
            matrix[i * n + j] = val;
            matrix[j * n + i] = val;
        }
    }
}

int count_edges(int n, int *matrix) {
    int edge_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edge_count += matrix[i * n + j];
        }
    }
    return edge_count;
}

void compute_degrees(int n, int *matrix, int *degrees) {
    for (int i = 0; i < n; i++) {
        degrees[i] = 0;
        for (int j = 0; j < n; j++) {
            degrees[i] += matrix[i * n + j];
        }
    }
}

int main() {
    int n_values[] = {1000, 2000, 3000, 4000, 5000};
    int num_n = sizeof(n_values) / sizeof(n_values[0]);

    srand(time(NULL)); // Seed random generator

    for (int i = 0; i < num_n; i++) {
        int n = n_values[i];
        int *matrix = (int *)calloc(n * n, sizeof(int)); // Initialize to 0
        int *degrees = (int *)malloc(n * sizeof(int));

        generate_graph(n, matrix); // Step 1: Generate graph

        struct timeval start, end;
        gettimeofday(&start, NULL); // Start timing Step 2

        int edge_count = count_edges(n, matrix); // Step 2a
        compute_degrees(n, matrix, degrees); // Step 2b

        int sum_degrees = 0; // Step 2c: Check handshake lemma
        for (int j = 0; j < n; j++) {
            sum_degrees += degrees[j];
        }

        gettimeofday(&end, NULL); // Stop timing Step 2

        double elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

        printf("n = %4d, Edges = %d, Time = %.2f ms\n", n, edge_count, elapsed);
        if (sum_degrees != 2 * edge_count) {
            printf("Handshaking lemma check failed for n = %d\n", n);
        }

        free(matrix);
        free(degrees);
    }

    return 0;
}
#include <stdio.h>
#define INF 1000000

void floydWarshall(int n, int dist[][100]) {
    for (int k = 0; k < n; k++)            // Intermediate vertex
        for (int i = 0; i < n; i++)        // Source vertex
            for (int j = 0; j < n; j++)    // Destination vertex
                if (dist[i][k] != INF && dist[k][j] != INF)
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // n = nodes, m = edges
    int dist[100][100];
    // Initialize distance matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = (i == j) ? 0 : INF;
    // Read edges and update distances
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (dist[u][v] > w) {
            dist[u][v] = w;
            dist[v][u] = w; // If undirected graph
        }
    }
    // Run Floyd-Warshall algorithm
    floydWarshall(n, dist);
    // Print final shortest paths
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }
    return 0;
}

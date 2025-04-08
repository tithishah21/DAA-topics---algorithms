#include <stdio.h>
#include <string.h>

#define V 100

int graph[V][V], visited[V];

int dfs(int u, int t, int flow, int n) {
    if (u == t) return flow;
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && graph[u][v] > 0) {
            int minFlow = dfs(v, t, flow < graph[u][v] ? flow : graph[u][v], n);
            if (minFlow > 0) {
                graph[u][v] -= minFlow;
                graph[v][u] += minFlow;
                return minFlow;
            }
        }
    }
    return 0;
}

int fordFulkerson(int s, int t, int n) {
    int maxFlow = 0, flow;
    do {
        memset(visited, 0, sizeof(visited));
        flow = dfs(s, t, 1e9, n);
        maxFlow += flow;
    } while (flow > 0);
    return maxFlow;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);  // n = nodes, m = edges
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        graph[u][v] = c;
    }

    int s, t;
    scanf("%d %d", &s, &t);  // source and sink
    printf("%d\n", fordFulkerson(s, t, n));
    return 0;
}

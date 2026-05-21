#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

int shortestPathKEdges(int graph[MAX][MAX], int n, int src, int dest, int k) {
    int dp[MAX][MAX];

    // Initialize all distances as infinite
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = INT_MAX;

    dp[src][0] = 0;

    // Build DP table
    for (int e = 1; e <= k; e++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graph[u][v] != 0 && dp[u][e-1] != INT_MAX) {
                    dp[v][e] = min(dp[v][e], dp[u][e-1] + graph[u][v]);
                }
            }
        }
    }

    return dp[dest][k];
}

int main() {
    int n;
    cin >> n;

    int graph[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int src, dest;
    cin >> src >> dest;

    int k;
    cin >> k;

    int result = shortestPathKEdges(graph, n, src-1, dest-1, k);

    if (result == INT_MAX)
        cout << "no path of length k is available";
    else
        cout << "Weight of shortest path from (" << src << "," << dest 
             << ") with " << k << " edges : " << result;

    return 0;
}

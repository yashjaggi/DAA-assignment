#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

void printPath(int parent[], int j) {
    if (j == -1)
        return;
    printPath(parent, parent[j]);
    cout << j << " ";
}

void bellmanFord(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    int parent[MAX];

    // Step 1: Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[src] = 0;

    // Step 2: Relax edges V-1 times
    for (int k = 0; k < n - 1; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graph[u][v] != 0 && dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v]) {

                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Step 3: Check negative cycle
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                cout << "Negative Cycle Exists\n";
                return;
            }
        }
    }

    // Step 4: Print paths
    for (int i = 0; i < n; i++) {
        if (i == src) continue;

        cout << "Vertex " << i << ": ";

        if (dist[i] == INT_MAX) {
            cout << "No path\n";
        } else {
            printPath(parent, i);
            cout << ": " << dist[i] << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int graph[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int src;
    cin >> src;

    bellmanFord(graph, n, src);

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;

bool isBipartite(int graph[MAX][MAX], int n) {
    int color[MAX];

    // Initialize all vertices as uncolored
    for (int i = 0; i < n; i++)
        color[i] = -1;

    // Handle disconnected graph
    for (int start = 0; start < n; start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v = 0; v < n; v++) {
                    if (graph[u][v] == 1) {
                        // If not colored, assign opposite color
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                        // If same color, not bipartite
                        else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[MAX][MAX];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    if (isBipartite(graph, n))
        cout << "Yes Bipartite";
    else
        cout << "Not Bipartite";

    return 0;
}

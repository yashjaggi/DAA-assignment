#include <iostream>
using namespace std;

const int MAX = 100;

bool dfs(int graph[MAX][MAX], int n, int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int v = 0; v < n; v++) {
        if (graph[node][v] == 1) {
            // If not visited, recurse
            if (!visited[v]) {
                if (dfs(graph, n, v, visited, recStack))
                    return true;
            }
            // If already in recursion stack → cycle
            else if (recStack[v]) {
                return true;
            }
        }
    }

    recStack[node] = false; // backtrack
    return false;
}

bool hasCycle(int graph[MAX][MAX], int n) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(graph, n, i, visited, recStack))
                return true;
        }
    }
    return false;
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

    if (hasCycle(graph, n))
        cout << "Yes Cycle Exists";
    else
        cout << "No Cycle Exists";

    return 0;
}

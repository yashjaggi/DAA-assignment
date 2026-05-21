#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;

struct Edge {
    int u, v, weight;
};

int parent[MAX];

// Find with path compression
int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

// Union
void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}

// Sort in descending order
bool compare(Edge a, Edge b) {
    return a.weight > b.weight;
}

void maxSpanningTree(int graph[MAX][MAX], int n) {
    vector<Edge> edges;

    // Convert matrix to edge list
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    // Sort edges in descending order
    sort(edges.begin(), edges.end(), compare);

    // Initialize DSU
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalWeight = 0;
    int edgeCount = 0;

    for (auto e : edges) {
        if (find(e.u) != find(e.v)) {
            unionSet(e.u, e.v);
            totalWeight += e.weight;
            edgeCount++;

            if (edgeCount == n - 1)
                break;
        }
    }

    cout << "Maximum Spanning Weight: " << totalWeight;
}

int main() {
    int n;
    cin >> n;

    int graph[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    maxSpanningTree(graph, n);

    return 0;
}

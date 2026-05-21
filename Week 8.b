#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;

struct Edge {
    int u, v, weight;
};

// Disjoint Set (Union-Find)
int parent[MAX];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]); // Path compression
}

void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

void kruskal(int graph[MAX][MAX], int n) {
    vector<Edge> edges;

    // Convert adjacency matrix to edge list
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // avoid duplicates
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    // Sort edges
    sort(edges.begin(), edges.end(), compare);

    // Initialize disjoint set
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int edgeCount = 0;
    int totalWeight = 0;

    for (auto e : edges) {
        if (find(e.u) != find(e.v)) {
            unionSet(e.u, e.v);
            totalWeight += e.weight;
            edgeCount++;

            if (edgeCount == n - 1)
                break;
        }
    }

    cout << "Minimum Spanning Weight: " << totalWeight;
}

int main() {
    int n;
    cin >> n;

    int graph[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    kruskal(graph, n);

    return 0;
}

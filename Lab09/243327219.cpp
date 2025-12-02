#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    int INF = 1000000000;
    vector<int> dist(n, INF);
    dist[0] = 0;

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "FALSE" << endl;
            return 0;
        }
    }

    cout << "TRUE" << endl;

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "INFINITY" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
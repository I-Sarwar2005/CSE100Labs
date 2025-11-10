#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void dfs1(int u, vector<vector<int>> &graph, vector<bool> &visited, stack<int> &st) {
    visited[u] = true;
    for (int v : graph[u])
        if (!visited[v])
            dfs1(v, graph, visited, st);
    st.push(u);
}

void dfs2(int u, vector<vector<int>> &rev_graph, vector<bool> &visited, vector<int> &component) {
    visited[u] = true;
    component.push_back(u);
    for (int v : rev_graph[u])
        if (!visited[v])
            dfs2(v, rev_graph, visited, component);
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V), rev_graph(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }

    vector<bool> visited(V, false);
    stack<int> st;

    // Step 1: DFS to fill stack by finishing times
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs1(i, graph, visited, st);

    fill(visited.begin(), visited.end(), false);
    vector<int> scc_id(V);

    // Step 2: DFS on reversed graph
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            vector<int> component;
            dfs2(node, rev_graph, visited, component);

            // Find the smallest index in this SCC
            int min_vertex = *min_element(component.begin(), component.end());
            for (int v : component)
                scc_id[v] = min_vertex;
        }
    }

    // Output SCC IDs
    for (int i = 0; i < V; i++)
        cout << scc_id[i] << endl;

    return 0;
}

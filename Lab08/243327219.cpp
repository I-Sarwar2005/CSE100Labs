#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int currV, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &endOrder){
    visited[currV] = true;
    for (int i = 0; i < graph[currV].size(); i++){
        int nextV = graph[currV][i];
        if (!visited[nextV]) {
            dfs(nextV, graph, visited, endOrder);
        }
    }
    endOrder.push_back(currV);
}

void dfsFlipped(int currV, vector<vector<int>> &flippedGraph, vector<bool> &visited, vector<int> &currSCC){
    visited[currV] = true;
    currSCC.push_back(currV);
    for (int i = 0; i < flippedGraph[currV].size(); i++){
        int nextV = flippedGraph[currV][i];
        if (!visited[nextV]) {
            dfsFlipped(nextV, flippedGraph, visited, currSCC);
        }
    }
}

int main() {
    int numV, numE;
    cin >> numV >> numE;
    vector<vector<int>> graph(numV);
    
    vector<vector<int>> flippedGraph(numV);

    for (int i = 0; i < numE; i++){
        int startV, endV;
        cin >> startV >> endV;
        graph[startV].push_back(endV);
        flippedGraph[endV].push_back(startV);
    }

    vector<bool> visited(numV, false);
    vector<int> endOrder;

    for (int i = 0; i < numV; i++){
        if (!visited[i]) {
            dfs(i, graph, visited, endOrder);
        }
    }

    reverse(endOrder.begin(), endOrder.end());
    vector<int> sccGroup(numV);

    for (int i = 0; i < visited.size(); i++){
        visited[i] = false;
    }

    for (int i = 0; i < endOrder.size(); i++){
        int currV = endOrder[i];
        if (!visited[currV]){
            vector<int> currSCC;
            dfsFlipped(currV, flippedGraph, visited, currSCC);
            int smallestV = *min_element(currSCC.begin(), currSCC.end());
            for (int j = 0; j < currSCC.size(); j++){
                int v = currSCC[j];
                sccGroup[v] = smallestV;
            }
        }
    }

    for (int i = 0; i < numV; i++){
        cout << sccGroup[i] << endl;
    }
    return 0;
}


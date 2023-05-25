#include <iostream>
#include <set>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    set<pair<int, int>> s;
    unordered_map<int, list<pair<int, int>>> adj;
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<int> dist(n, INT_MAX);
    cout << "Enter the number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int source;
    cout << "Enter the source: ";
    cin >> source;
    dist[source] = 0;
    s.insert(make_pair(0, source));

    while (!s.empty()) {
        auto top = *(s.begin());
        int nodeDist = top.first;
        int topNode = top.second;

        s.erase(s.begin());

        for (auto neighbor : adj[topNode]) {
            int neighborNode = neighbor.first;
            int neighborWeight = neighbor.second;

            if (nodeDist + neighborWeight < dist[neighborNode]) {
                auto record = s.find(make_pair(dist[neighborNode], neighborNode));
                if (record != s.end()) {
                    s.erase(record);
                }
                dist[neighborNode] = nodeDist + neighborWeight;
                s.insert(make_pair(dist[neighborNode], neighborNode));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << dist[i] << endl;
    }

    return 0;
}

#include <vector>
#include <queue>
using namespace std;


vector<int> bfs(const vector<vector<int> > &graph, vector<int> &points, int n) {
    vector<int> dist(n, 1e9);
    queue<int> q;

    for (auto i : points) {
        q.push(i);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                q.push(to);
                dist[to] = dist[v] + 1;
            }
        }
    }
    return dist;
}


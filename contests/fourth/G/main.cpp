//bfs 0-1

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int max_v = 100000;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> dist(n, max_v);
    deque<int> q;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].emplace_back(b, 0);
        graph[b].emplace_back(a, 1);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int start, finish;
        cin >> start >> finish;
        --start, --finish;

        dist.assign(n, max_v);
        dist[start] = 0;
        q.push_back(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            for (auto [u, w]: graph[v]) {
                if (dist[v] + w < dist[u]) {
                    dist[u] = dist[v] + w;
                    if (w == 0){
                        q.push_front(u);
                    }
                    else q.push_back(u);
                }
            }
        }

        if (dist[finish] == max_v) {
            cout << -1 << '\n';
        } else {
            cout << dist[finish] << '\n';
        }
    }
    return 0;
}
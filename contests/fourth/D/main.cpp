#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;
vector<int> h;
vector<int> visited;
vector<vector<int>> g;
queue<int> q;
set<int> ans;

int main() {
    int n;
    cin >> n;
    h.resize(n);
    g.resize(n);
    visited.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);

    }

    visited[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        bool moving = false;
        for (int u : g[v]) {
            if (h[u] < h[v]) {
                moving = true;
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }

        if (!moving) {
            ans.insert(v + 1);
        }
    }

    for (int v : ans) {
        cout << v << ' ';
    }
    return 0;
}
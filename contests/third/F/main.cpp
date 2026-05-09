
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> color;
vector<int> dist;
const int INF = numeric_limits<int>::max();

void dfs(int ver) {
    color[ver] = 1;

    for (auto [u, w] : g[ver]) {
        if (color[u] == 0) {
            dfs(u);
        }
        if (dist[u] != INF) {
            dist[ver] = min(dist[ver], dist[u] + w);
        }
    }
    color[ver] = 2;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s, --t;

    g.resize(n);
    color.resize(n);
    dist.resize(n, INF);
    dist[t] = 0;

    for (int i = 0; i < m; ++i) {
        int b, e, w;
        cin >> b >> e >> w;
        --b, --e;
        g[b].emplace_back(e, w);
    }

    dfs(s);

    if (dist[s] != INF) {
        cout << dist[s] << '\n';
    } else {
        cout << "Unreachable" << '\n';
    }

    return 0;
}
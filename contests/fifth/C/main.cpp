#include <iostream>
#include <vector>
#include <set>
using namespace std;

int big = 2009000999;

vector<int> dijkstra(int const n, int const s, vector<vector<pair<int, int>>> const &g) {
    vector<int> d(n, big);
    d[s] = 0;
    set< pair<int, int> > q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [u, w] : g[v]) {
            if (d[u] > d[v] + w) {
                q.erase({d[u], u});
                d[u] = d[v] + w;
                q.insert({d[u], u});
            }
        }
    }
    return d;
}

int main() {
    int K;
    cin >> K;
    vector<vector<int>> res(K);

    for (int i = 0; i < K; ++i) {
        int N, M;
        cin >> N >> M;
        vector<vector<pair<int, int>>> g(N);
        for (int j = 0; j < M; ++j) {
            int a, b, w;
            cin >> a >> b >> w;
            g[a].emplace_back(b, w);
            g[b].emplace_back(a, w);
        }
        int S;
        cin >> S;
        res[i] = dijkstra(N, S, g);
    }

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
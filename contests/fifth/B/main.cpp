#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> g;
int N, M, S, F;
int inf = 1e9;

vector<int> dijkstra(int s, vector<int> &p) {
    vector<int> d(N, inf), a(N, 0);
    d[s] = 0;
    for (int i = 0; i < N; i++) {
        // находим вершину с минимальным d[v] из ещё не помеченных
        int v = -1;
        for (int u = 0; u < N; u++)
            if (!a[u] && (v == -1 || d[u] < d[v]))
                v = u;
        // помечаем её и проводим релаксации вдоль всех исходящих ребер
        a[v] = true;
        for (auto [u, w] : g[v])
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                p[u] = v;
            }
    }
    return d;
}

int main() {
    cin >> N >> M;
    cin >> S >> F;
    --S; --F;

    g.resize(N);
    vector<int>  parents(N, -1);

    for (int i = 0; i < M; ++i) {
        int b, e, w;
        cin >> b >> e >> w;
        --b, --e;
        g[b].emplace_back(e, w);
        g[e].emplace_back(b, w);
    }

    vector<int> dist = dijkstra(S, parents);
    if (dist[F] == inf) {
        cout << -1 << '\n';
    } else {
        cout << dist[F] << '\n';
        //порядок обхода
        vector<int> res;
        for (int i = F; i != S; i = parents[i]) {
            res.emplace_back(i+1);
        }
        res.emplace_back(S+1);
        for (int i = res.size() - 1 ; i >= 0; --i) {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

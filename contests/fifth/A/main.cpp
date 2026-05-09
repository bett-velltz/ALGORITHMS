#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> g;
int N, S, F;
int inf = 1e9;

vector<int> dijkstra(int s) {
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
            d[u] = min(d[u], d[v] + w);
    }
    return d;
}


int main() {
    cin >> N >> S >> F;
    --S; --F;

    g.resize(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int el;
            cin >> el;
            if (el != -1) {
                g[i].emplace_back(j, el);
            }
        }
    }

    if (dijkstra(S)[F] == inf) {
        cout << -1 << '\n';
    } else {
        cout << dijkstra(S)[F] << '\n';
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<vector<pair<int, long long>>> graph;
vector<int> parents;

const int maxn = 1e5;
const long long inf = 1e18;

vector<long long> dijkstra(int s, int n) {
    vector<long long> d(n, inf), a(n, 0);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        // находим вершину с минимальным d[v] из ещё не помеченных
        int v = -1;
        for (int u = 0; u < n; u++)
            if (!a[u] && (v == -1 || d[u] < d[v]))
                v = u;
        // помечаем её и проводим релаксации вдоль всех исходящих ребер
        a[v] = true;
        for (auto [u, w] : graph[v]) {
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                parents[u] = v;
            }
        }
    }
    return d;
}

int main() {
    int n, m, v_1, v_2, v_3, v_4;
    cin >> n >> m;
    cin >>  v_1 >> v_2 >> v_3 >> v_4;
    --v_1, --v_2, --v_3, --v_4;

    graph.resize(n);
    parents.resize(n);

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    if (dijkstra(v_4, n)[v_3] == inf || dijkstra(v_3, n)[v_2] == inf || dijkstra(v_2, n)[v_1] == inf) {
        cout << -1 << '\n';
        return 0;
    }
    int ans = dijkstra(v_4, n)[v_3] + dijkstra(v_3, n)[v_2] + dijkstra(v_2, n)[v_1];

    cout << ans << '\n';
    return 0;
}
//Дан ориентированный ацикличный граф. Проверить, что существует единственный топологический порядок вершин графа.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g;
vector<int> order;
vector<int> color;

void dfs(int ver) {
    color[ver] = 1;
    for (auto u : g[ver]) {
        if (color[u] == 0) {
            dfs(u);
        }
    }
    color[ver] = 2;
    order.emplace_back(ver+1);
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    color.resize(n, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].emplace_back(b);
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());

    bool fl = true;
    for (int i = 0; i < order.size() - 1; ++i) {
        int a = order[i]-1;
        int b = order[i+1]-1;
        if (find(g[a].begin(), g[a].end(), b) != g[a].end()) continue;
        else {
            fl = false;
            break;
        }
    }

    if (!fl) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    for (int i = 0; i < order.size(); ++i) {
        cout << order[i] << ' ';
    }
    cout << '\n';
    return 0;
}
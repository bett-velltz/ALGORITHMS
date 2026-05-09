#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

vector<vector<int>> g;
vector<vector<int>> rev_g;
vector<int> comp;

vector<int> order;
vector<int> color;

void top_dfs(int ver) {
    color[ver] = 1;
    for (auto u : g[ver]) {
        if (color[u] == 0) {
            top_dfs(u);
        }
    }
    color[ver] = 2;
    order.emplace_back(ver);
}

void dfs(int ver, int cnt) {
    color[ver] = 1;
    for (auto u : rev_g[ver]) {
        if (color[u] == 0) {
            dfs(u, cnt);
        }
    }
    color[ver] = 2;
    comp[ver] = cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    rev_g.resize(n);
    comp.resize(n, -1);
    color.resize(n, 0);

    for (int i = 0; i < m; ++ i) {
        int b_i, e_i;
        cin >> b_i >> e_i;
        --b_i, --e_i;
        g[b_i].emplace_back(e_i);
        rev_g[e_i].emplace_back(b_i);
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            top_dfs(i);
        }
    }
    reverse(order.begin(), order.end());

    color.assign(n, 0);
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (color[order[i]] == 0) {
            dfs(order[i], cnt);
            ++cnt;
        }
    }

    cout << cnt-1 << '\n';
    for (int i = 0; i < n; ++i) {
        cout << comp[i] << ' ';
    }
    cout << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<vector<int>> g;
vector<int> visited;

void dfs (int w) {

    visited[w] = 1;
    for (auto u : g[w]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    visited[w] = 2;
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    visited.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        g[a].emplace_back(i);
        g[i].emplace_back(a);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
            ++cnt;
        }
    }

    cout << cnt << '\n';
    return 0;
}
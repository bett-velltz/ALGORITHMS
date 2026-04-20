#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> visited;
int cnt = 0;
vector<int> comp;

void dfs (int w) {
    comp[w] = cnt;
    for (auto u: v[w]) {
        if (visited[u] == 0) {
            visited[u] = 1;
            dfs(u);
        } else continue;
    }

}

int main() {
    int n, m;
    cin >> n >> m;

    v.resize(n);
    comp.resize(n, 0);
    visited.resize(n, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a-1].emplace_back(b-1);
        v[b-1].emplace_back(a-1);
    }

    for (int j = 0; j < n; ++j) {
        if (visited[j] == 0) {
            ++cnt;
            visited[j] = 1;
            dfs(j);
        }
    }

    cout << cnt << '\n';
    for (int j = 0; j < n; ++j) {
        cout << comp[j] << ' ';
    }
    return 0;
}
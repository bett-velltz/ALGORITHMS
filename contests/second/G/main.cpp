#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> visited;
vector<int> tin;
vector<int> tout;
vector<pair<int, int>> ab;
int n, m;
int t = 0;

void dfs (int w) {
    tin[w] = t;
    ++t;
    visited[w] = 1;
    for (auto u : v[w]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    tout[w] = t;
}

int main() {

    cin >> n;
    v.resize(n);
    tin.resize(n);
    tout.resize(n);
    visited.resize(n, 0);

    int root;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a != 0) {
            v[a-1].emplace_back(i);
        } else {
            root = i;
        }
    }
    dfs(root);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        ab.emplace_back(a, b);
    }
    for (int i = 0; i < m; ++i) {
        if (tin[ab[i].first] <= tin[ab[i].second] && tout[ab[i].first] >= tout[ab[i].second]) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
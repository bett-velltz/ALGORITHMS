#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> g;

long ans = 0;
long n, r, k;

vector<pair<int, int>> subtree;
vector<int> cut;
vector<int> removed;
vector<int> parent;

void dfs(int x, int p) {
    parent[x] = p;
    subtree[x].second = 1;
    for (auto u : g[x]) {
        if (u.first != p) {

            dfs(u.first, x);
            subtree[x].second += subtree[u.first].second;

            if (u.second == 1) {
                cut[u.first] = 1;
            }
        }
    }
}

void remove(int x, int p) {
    removed[x] = true;
    for (auto u : g[x]) {
        if (u.first != p) {
            remove(u.first, x);
        }
    }
}

int main() {
    cin >> n >> r >> k;
    --r;
    g.resize(n);
    removed.resize(n, false);
    cut.resize(n, 0);
    parent.resize(n, -1);

    for (int i = 0; i < n; ++i) {
        subtree.emplace_back(i, 0);
    }


    for (auto i = 0; i < n-1; ++i) {
        long v, u, w;
        cin >> v >> u >> w;
        --v; --u;
        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);
    }

    dfs(r, -1);
    sort(subtree.begin(), subtree.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; });

    int res = 0;
    int cities = 0;

    for (int i = 0; i < n && cities < k; ++i) {
        if (subtree[i].first != r && !removed[subtree[i].first] && cut[subtree[i].first] == 1) {
            cities += subtree[i].second;
            res++;
            remove(subtree[i].first, parent[subtree[i].first]);
        }
    }

    if (cities >= k) {
        cout << res << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
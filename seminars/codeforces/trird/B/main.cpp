#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(const vector<vector<int>> &v, int u) {
    int res = 0;
    for (auto w : v[u]) {
        res = max(dfs(v, w), res);
    }
    return res + 1;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n);
    vector<int> roots;
    vector<int> variants;

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        if (p == -1) {
            roots.emplace_back(i);
            continue;
        }
        v[p-1].emplace_back(i);
    }

    int max_res = 0;
    for (auto u : roots) {
        max_res = max(max_res, dfs(v, u));
    }

    cout << max_res << '\n';

    return 0;
}
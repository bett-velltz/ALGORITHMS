#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(vector<int> &vec,
         vector<int> &used,
         vector<int> &tin,
         vector<int> low,
         int v, int p, int time) {
    used[v] = 1;
    ++time;
    tin[v] = time;
    low[v] = time;
    for (auto u : vec[v]) {}
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n);
    vector<int> used (n, 0);
    vector<int> tin (n, 0);
    vector<int> low (n, 0);
    int time;

    for (int i = 0; i < m; ++i) {
        int a_i, b_i;
        cin >> a_i >> b_i;
        vec[a_i-1].emplace_back(b_i-1);
        vec[b_i-1].emplace_back(a_i-1);
    }
    return 0;
}


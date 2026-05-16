#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    int new_m = 0;
    cin >> n >> m;

    vector<vector<int>> g(n);
    set<pair<int, int>> s;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a == b) continue;
        if (a <= b) {
            if (s.find({a, b}) != s.end()) continue;
            g[a].emplace_back(b);
            s.insert({a, b});
        } else {
            if (s.find({b, a}) != s.end()) continue;
            g[b].emplace_back(a);
            s.insert({b, a});
        }
        ++new_m;
    }

    cout << n << ' ' << new_m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            cout << i+1 << ' ' << g[i][j] + 1 << '\n';
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<int> p, r;
vector<vector<int>> vec;

int dsu_get(int v) {
    if (v == p[v]) return v;
    return p[v] = dsu_get(p[v]);
}

int main() {
    int n;
    cin >> n;

    p.resize(n + 1);
    r.assign(n + 1, 1);
    vec.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        vec[i] = {i};
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        int ru = dsu_get(u), rv = dsu_get(v);
        if (r[ru] < r[rv]) swap(ru, rv);
        for (int x : vec[rv])
        vec[ru].push_back(x);
        vec[rv].clear();
        p[rv] = ru;
        r[ru] += r[rv];
    }

    int root = dsu_get(1);
    for (int i = 0; i < n; i++)
        cout << vec[root][i] << " ";
    return 0;
}
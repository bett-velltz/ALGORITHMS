#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>

using namespace std;
const int INF = INT_MAX;

vector<int> p;
vector<int> rang;

int dsu_get(int v) {
    if (v == p[v])
        return v;
    return p[v] = dsu_get(p[v]);
}

void dsu_unite(int a, int b) {
    int x = dsu_get(a);
    int y = dsu_get(b);
    if (x != y) {
        if (rang[x] > rang[y])
            swap(x, y);
        p[x] = y;
        rang[y] += rang[x];
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<pair<long double, int>>> gr (n);
    vector<int> X(n);
    vector<int> Y(n);


    p.resize(n);
    rang.resize(n, 0);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        dsu_unite(a, b);
    }

    vector<long double>  key(n, INF);
    vector<bool> used(n, false);
    long double ans = 0;
    key[0]  = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dsu_get(i) != dsu_get(j)) {
                double weight = sqrt((X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]));
                gr[i].emplace_back(weight, j);
                gr[j].emplace_back(weight, i);
            } else {
                gr[i].emplace_back(0, j);
                gr[j].emplace_back(0, i);
            }
        }
    }

    for (int i = 0; i < n; ++i) {

        long double min_edge = INF;
        int new_v    = -1;

        for (int v = 0; v < n; ++v) {
            if (!used[v] && min_edge > key[v]) {
                min_edge = key[v];
                new_v = v;
            }
        }

        used[new_v]  = true;
        ans += min_edge;

        for (auto [w, u] : gr[new_v]) {
            key[u] = min(w, key[u]);
        }
    }

    cout << fixed << setprecision(6) << ans << "\n";

    return 0;
}

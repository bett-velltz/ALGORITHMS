
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> p;

int dsu_get(int v) {
    if (v == p[v])
        return v;
    return p[v] = dsu_get(p[v]);
}

void dsu_unite(int a, int b) {
    int x = dsu_get(a);
    int y = dsu_get(b);
    if (x != y) {
        p[x] = y;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    p.resize(n);

    for (auto i = 0; i < n; i++) {
        p[i] = i;
    }

    vector<int> v(n);
    for (auto i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (auto i = 0; i < m; ++i) {
        long u, w;
        cin >> u >> w;
        --u, --w;
        dsu_unite(u, w);
    }

    // для каждой компоненты собираем позиции и значения
    vector<vector<int>> ind(n);
    vector<vector<int>> numb(n);

    for (int i = 0; i < n; ++i) {
        int r = dsu_get(i);
        ind[r].push_back(i);
        numb[r].push_back(v[i]);
    }

    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
        if (ind[i].empty()) continue;

        // позиции по возрастанию, значения по убыванию
        sort(ind[i].begin(), ind[i].end());
        sort(numb[i].begin(), numb[i].end(), greater<int>());

        for (int j = 0; j < ind[i].size(); ++j)
            ans[ind[i][j]] = numb[i][j];
    }

    for (auto i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}

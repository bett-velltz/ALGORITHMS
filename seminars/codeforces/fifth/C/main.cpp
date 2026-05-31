//
// Created by 1 on 18.05.2026.
//
#include <iostream>
#include <vector>
#include <set>

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
    int n;
    cin >> n;
    p.resize(n);

    vector<int> numb(n);
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> numb[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    // Инициализация DSU
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    /*Для каждой ячейки и смотрим ее любимое число d[i]и объединяемся iс соседями, с которыми она может поменяться:
    для каждого i от 1 до n:
    если i + d[i] <= n:  объединить i и i+d[i]
    если i - d[i] >= 1:  объединить i и i-d[i] */
    for (int i = 0; i < n; i++) {
        if (i + d[i] < n)
            dsu_unite(i, i + d[i]);
        if (i - d[i] >= 0)
            dsu_unite(i, i - d[i]);
    }

    // Собираем позиции и значения для каждой компоненты
    vector<vector<int>> comp(n);
    vector<vector<int>> val(n);
    for (int i = 0; i < n; ++i) {
        int r = dsu_get(i);
        comp[r].emplace_back(i+1);
        val[r].emplace_back(numb[i]);
    }

    for (int i = 0; i < n; i++) {
        set<int> comp_set(comp[i].begin(), comp[i].end());
        set<int> val_set(val[i].begin(), val[i].end());
        if (comp_set != val_set) {
            cout << "NO\n";
            return 0;
        }
    }


    cout << "YES\n";
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;
vector<int> c;
//vector<vector<int>> gr; - не нужен
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
    int n, k, m;
    cin >> n >> m >> k;

    c.resize(k);
    p.resize(n);

    for (int i = 0; i < k; ++i) {
        cin >> c[i];
        --c[i];
    }

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        dsu_unite(u, v);
    }

    //есть ли в комп связ столица (есть - номер, нет - -1)
    vector<int> cap(n, -1);

    //смотрим, в какой компоненте какая столица (по корню dsu)
    for (int j = 0; j < k; ++j) {
        int r = dsu_get(c[j]);
        cap[r] = c[j];
    }

    vector<int> comp_size(n, 0);
    for (int i = 0; i < n; i++) {
        int r = dsu_get(i);
        ++comp_size[r];
    }

    //ищем компоненту с максимальным размером и столицей!
    int max_s = -1;
    int comp_max_s;

    for (int i = 0; i < n; ++i) {
        if (cap[i] != -1 && comp_size[i] > max_s) {
            comp_max_s = i;
            max_s = comp_size[comp_max_s];
        }
    }

    long long ans = -m; // Для каждого компонента s максимальный размер =s*(s-1)/2 и заранее вычтем то, что уже есть
    for (int i = 0; i < n; i++) {
        //ans += (comp_size[i] * (comp_size[i] - 1) / 2); // соединяем всё внутри команенты вне зависимости от столицы
        if (cap[i] == -1) {
            comp_size[comp_max_s] += comp_size[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (cap[i] != -1) {
            ans += comp_size[i] * (comp_size[i] - 1) / 2;
        }
    }
    //берем только со столицами - к ним уже всё присоединили

    cout << ans << '\n';
    return 0;
}

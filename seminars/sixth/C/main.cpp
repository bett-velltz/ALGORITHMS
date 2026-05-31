#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <climits>
#include <set>

//изначально все со всеми связаны - полный граф
using namespace std;
const int INF = INT_MAX;

//Нам не нужно хранить оба конца ребра — достаточно знать куда ведёт ребро (вершину u) и его вес. Откуда оно идёт неважно, потому что мы всегда берём минимальное ребро из уже посещённых вершин в ещё не посещённые.

int main() {
    int n;
    cin >> n;

    vector<int> X(n);
    vector<int> Y(n);

    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i];
    }

    vector<int>  key(n, INF);
    vector<bool> used(n, false);
    long long ans = 0;
    key[0]  = 0;

    for (int i = 0; i < n; ++i) {

        int min_edge = INF;
        int new_v    = -1;

        for (int v = 0; v < n; ++v) {
            if (!used[v] && min_edge > key[v]) {
                min_edge = key[v];
                new_v    = v;
            }
        }

        used[new_v]  = true;
        ans         += min_edge;

        // 3. Обновить ключи соседей. может быть такое, что есть несколько вариантов подключения вершины к дереву через разные уже включенные
        for (int u = 0; u < n; ++u) {
            int d = abs(X[new_v]-X[u]) + abs(Y[new_v]-Y[u]);
            key[u] = min(d, key[u]);
        }
    }

    cout << ans*2 << "\n";

    return 0;
}

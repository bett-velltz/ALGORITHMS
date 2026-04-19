/*проверка, является ли граф деревом
1. Проверяем m == n-1
2. Строим список смежности
3. Запускаем DFS от вершины 0
4. В DFS проверяем:
- Не заходим ли в уже посещённую вершину (кроме родителя)
- Считаем количество посещённых вершин
5. Проверяем, что посетили все n вершин*/

#include <iostream>
#include <vector>

using namespace std;

bool dfs(int u, vector<int> &used, const vector<vector<int>> &v, int p, int &cnt) {
    used[u] = 1;
    ++cnt;

    for (auto w : v[u]) {
        if (w != p) {
            if (used[w] == 0) {
                if (!dfs(w, used, v, u, cnt)) {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    used[u] = 2;
    return true;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n);
    for (int i = 0; i < m; ++i) {
        int a_i, b_i;
        cin >> a_i >> b_i;
        v[a_i-1].emplace_back(b_i-1);
        v[b_i-1].emplace_back(a_i-1);
    }
    if (n <= 1) {
        cout << "YES" << '\n';
        return 0;
    }
    if (m != n-1) {
        cout << "NO" << '\n';
        return 0;
    }

    vector<int> visited(n, 0);
    int cnt = 0;

    if (!dfs(0, visited, v, -1, cnt)) {
        cout << "NO" << '\n';
        return 0;
    }
    if (cnt != n) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    return 0;
}

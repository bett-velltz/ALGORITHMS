#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> color;
bool dicotyledonous = true;

void dfs (int w) {
    for (auto u: v[w]) {
        if (color[u] == 0) {
            if (color[w] == 1) {
                color[u] = 2;
            } else if (color[w] == 2) {
                color[u] = 1;
            }
            dfs(u);
        } else if (color[u] == color[w]) {
            dicotyledonous = false;
            return;
        } else continue;
    }

}

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << "YES" << '\n';
        return 0;
    }
    v.resize(n);
    color.resize(n, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a-1].emplace_back(b-1);
        v[b-1].emplace_back(a-1);
    }
    //делаем дфс для всех компонент связности
    for (int j = 0; j < n; ++j) {
        //проверяем, новая ли компонента связности
        if (color[j] == 0) {
            color[j] = 1;
            dfs(j);
            if (!dicotyledonous) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }

    cout << "YES" << '\n';
    return 0;
}
//Дан ориентированный невзвешенный граф. Необходимо определить есть ли в нём циклы, и если есть, то вывести любой из них.

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> color;
vector<int> parent;
int start;
int finish;

bool dfs(int u) {
    color[u] = 1;
    for (auto w : v[u]) {
        if (color[w] == 0) {
            parent[w] = u;
            if (dfs(w)) return true;
        }
        if (color[w] == 1) {
            start = w;
            finish = u;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    v.resize(n+1);
    color.resize(n+1, 0);
    parent.resize(n+1, -1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
    }
    for (int i = 1; i < n+1; ++i) {
        if (color[i] == 0) {
            if (dfs(i)) {
                cout << "YES" << '\n';
                vector<int> res;
                res.emplace_back(start);

                for (int j = finish; j != start; j = parent[j]) {
                    res.emplace_back(j);
                }
                for (int l = res.size() - 1; l >= 0; --l) {
                    cout << res[l] << ' ';
                }
                cout << '\n';
                return 0;
            }
        }
    }
    cout << "NO" << '\n';
    return 0;
}

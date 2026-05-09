#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

vector<int> g;
vector<int> color;
int cycles = 0;

void dfs(int ver) {
    color[ver] = 1;
    if (color[g[ver]] == 0) {
        dfs(g[ver]);
    } else if (color[g[ver]] == 1) {
        ++cycles;
    }

    color[ver] = 2;
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    color.resize(n, 0);
    vector<int> in_degree(n, 0);

    for (int i = 0; i < n; ++ i) {
        int a;
        cin >> a;
        --a;
        g[i] = a;
        ++in_degree[a];
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    // Логика ответа:
    // 1. Если циклов больше 1, нужно перенастроить ровно столько катапульт, сколько циклов.
    // 2. Если цикл ровно 1:
    //    а) Если у всех вершин входящая степень 1, значит это один большой цикл длины N. Ответ 0.
    //    б) Иначе (есть деревья, входящие в цикл), нужно 1 изменение.

    if (cycles == 1) {
        bool fl = true;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 1) continue;
            else {
                fl = false;
                break;
            }
        }
        if (fl) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
        }
    } else {
        cout << cycles << '\n';
    }
    return 0;
}
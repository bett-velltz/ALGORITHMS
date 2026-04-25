#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> v;
set<pair<int, int>> s;
vector<int> order;
vector<int> color;
bool flag = false;

void dfs(int ver) {
    color[ver] = 1;
    for (auto u : v[ver]) {
        if (color[u] == 1) {
            flag = true;
            return;
        }
        if (color[u] != 2) {
            dfs(u);
        }
    }
    color[ver] = 2;
    order.emplace_back(ver+1);
}

int main () {
    int n, m;
    cin >> n >> m;
    v.resize(n);
    color.resize(n, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (s.find({a, b}) == s.end()) {
            v[a-1].emplace_back(b-1);
            s.insert({a, b});
        }
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i);
        }
    }

    if (!flag) {
        //выводим
        cout << "Yes" << '\n';
        for (int j = order.size() - 1; j >= 0; --j) {
            cout << order[j] << ' ';
        }
        cout << '\n';
    } else {
        cout << "No" << '\n';
        return 0;
    }
}
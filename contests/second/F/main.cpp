#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> v;
vector<int> visited;
int a, b;

void dfs (int w, int t) {
    visited[w] = 1;
    for (auto l : v[w]) {
        int u = l.first;
        int h_u = l.second;
        if (visited[u] == 0 && h_u > t) {
            dfs(u, t);
        }
    }
}
bool fun(int x) {
    visited.assign(a, false);
    dfs(0, x);
    for (int i = 1; i < a; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    cin >> a >> b;
    v.resize(a);
    int maxh = 0;
    for (int i = 0; i < b; i++) {
        int s, f, h;
        cin >> s >> f >> h;
        v[s-1].emplace_back(f-1, h);
        v[f-1].emplace_back(s-1, h);
        maxh = max(maxh, h);
    }

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r)/2;
        if (!fun(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
    return 0;
}
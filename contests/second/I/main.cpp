#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int> dist;
int n;

void dfs (int w, int p) {
    for (auto u : v[w]) {
        if (u != p) {
            dist[u] = dist[w] + 1;
            dfs(u, w);
        }
    }
}

int main() {

    cin >> n;
    v.resize(n + 1);
    dist.resize(n + 1, 0);

    if (n == 1) {
        cout << 0 << '\n';
        cout << 1 << '\n';
        cout << 1 << '\n';
        return 0;
    }

    for (int i = 2; i < n+1; ++i) {
        int x;
        cin >> x;
        v[x].emplace_back(i);
    }

    dfs(1, -1);
    auto a_ = max_element(dist.begin(), dist.end());
    int a  = distance(dist.begin(), a_);
    int dist_x = dist[a];
    int cnt = count(dist.begin(), dist.end(), dist_x);

    cout << dist[a] << '\n';
    cout << cnt << '\n';
    for (int i = 1; i < n+1; ++i) {
        if (dist[i] == dist_x) {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}
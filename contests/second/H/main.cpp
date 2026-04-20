#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;  // дерево
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
    v.resize(n+1);
    dist.resize(n + 1);

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }

    dist.assign(n + 1, 0);
    dfs(1, -1);
    auto a_ = max_element(dist.begin(), dist.end());
    int a  = distance(dist.begin(), a_);

    dist.assign(n + 1, 0);
    dfs(a, -1);
    auto b_ = max_element(dist.begin(), dist.end());
    int b  = distance(dist.begin(), b_);

    cout << dist[b] << ' ';
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> visited;

int start, finish;
vector<int> pred;

bool dfs (int w, int p) {
    visited[w] = 1;
    for (auto u: v[w]) {
        if (u == p) continue;

        if (visited[u] == 0) {
            pred[u] = w;
            if (dfs(u, w)) {
                return true;
            }
        } else if (visited[u] == 1) {
                start = u;
                finish = w;
                return true;
        }
    }
    visited[w] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    v.resize(n);
    pred.resize(n, -1);
    visited.resize(n, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a-1].emplace_back(b-1);
        v[b-1].emplace_back(a-1);
    }

    for (int j = 0; j < n; ++j) {
        if (visited[j] == 0) {
            if (dfs(j, -1)) {

                vector<int> cycle;

                for (int i = finish; i != start; i = pred[i]) {
                    cycle.emplace_back(i);
                }
                cycle.emplace_back(start);

                cout << "YES" << '\n';

                cout << cycle.size() << '\n';
                for (int i = cycle.size() - 1; i >= 0; --i) {
                    cout <<  cycle[i] + 1 << ' ';
                }
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "NO" << '\n';
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> g;
priority_queue<int, vector<int>, greater<int> > q;
vector<int> indeg;
vector <int> ans;

int main() {
    int n, m;
    cin >> n >> m;

    g.resize(n);
    indeg.resize(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v);
        ++indeg[v];
    }

    for (int i = 0; i < n; ++i){
        if (indeg[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty()){
        int v = q.top();
        q.pop();
        ans.push_back(v+1);
        for (int u: g[v]){
            indeg[u]--;
            if (indeg[u] == 0){
                q.push(u);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<vector<int>>> gr;

int n, m;
int inf = 1e9;

vector<int> dijkstra(int s) {
    vector<int> d(n, inf);
    d[s] = 0;
    set< pair<int, int> > q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto l : gr[v]) {
            int u = l[0];
            int time = l[1];
            int red = l[2];
            int green = l[3];

            int ext_time = d[v] % (red + green);
            int new_d = d[v] + time;
            if (ext_time < red) {
                new_d += (red - ext_time);
            }
            if (d[u] > new_d) {
                q.erase({d[u], u});
                d[u] = new_d;
                q.insert({d[u], u});
            }
        }
    }
    return d;
}

int main() {

    cin >> n >> m;
    gr.resize(n);

    for (int i = 0; i < m; ++i) {
       int a, b, t, r, g;
       cin >> a >> b >> t >> r >> g;
       --a, --b;
       gr[a].push_back({b, t, r, g});
    }

    vector<int> res = dijkstra(0);
    cout << res[n-1] << '\n';
    return 0;
}
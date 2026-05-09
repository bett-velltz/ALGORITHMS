#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<vector<long long>> gr;

int n, m;
long long INF = 1e18;

vector<long long> dijkstra(int s) {
    vector<long long> dist(n*m, INF);
    dist[s] = 0;

    using pii = pair<long long, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d > dist[v]) continue;

        int x = v/m;
        int y = v%m;


        vector<int> neigh;
        if (x>0) {
            neigh.emplace_back((x-1)*m + y);
            //номер клетки
        }
        if (y>0) {
            neigh.emplace_back(x*m + y - 1);
        }
        if (x< n-1) {
            neigh.emplace_back((x+1)*m + y);
        }
        if (y < m-1) {
            neigh.emplace_back(x*m + y + 1);
        }

        for (auto l : neigh) {
            if (dist[l] > dist[v] + gr[l/m][l%m]) {
                dist[l] = dist[v] + gr[l/m][l%m];
                pq.push({dist[l], l});
            }
        }
    }
    return dist;
}

int main() {

    cin >> n >> m;
    gr.resize(n, vector<long long>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> gr[i][j];
        }
    }

    vector<long long> res = dijkstra(0);
    cout << res[n*m-1] << '\n';
    return 0;
}
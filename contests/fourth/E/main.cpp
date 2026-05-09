#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

vector<int> shops;
vector<vector<int>> roads;
vector<int> min_dist;
queue<int> q;

int main() {
    int n, k, m;
    cin >> n >> k;
    roads.resize(n);
    min_dist.resize(n, -1);
    vector<int> shop_id(n, -1);

    for (int i = 0; i < k; ++i) {
        int numb;
        cin >> numb;
        --numb;
        shops.emplace_back(numb);
        min_dist[numb] = 0;
        shop_id[numb] = numb + 1;
        q.push(numb);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        roads[a].emplace_back(b);
        roads[b].emplace_back(a);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : roads[v]) {
            if (min_dist[u] == -1) {
                shop_id[u] = shop_id[v];
                min_dist[u] = min_dist[v] + 1;
                q.push(u);
            } else if (min_dist[u] == min_dist[v] + 1) {//другой магазин на том же расстоянии
                if (shop_id[v] < shop_id[u]) {
                    shop_id[u] = shop_id[v];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << min_dist[i] << ' ';
    }
    cout << '\n';

    for (int i = 0; i < n; i++) {
        cout << shop_id[i] << ' ';
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <climits>
#include <set>

using namespace std;
const int INF = INT_MAX;

int main() {
    ifstream file("input.txt");

    int n, m;
    file >> n >> m;

    vector<vector<pair<int,int>>> g(n);

    string line;

    for (int i = 0; i < m; ++i) {
        int b, e, w;
        file >> b >> e >> w;
        -- b, --e;
        g[b].push_back({w, e});
        g[e].push_back({w, b});
    }

    multiset<pair<int,int>> edge;
    vector<bool> used(n, false);
    long long ans = 0;

    edge.insert({0, 0});
    while (!edge.empty()) {

        auto [w, v] = *edge.begin();
        edge.erase(edge.begin());

        if (used[v])
            continue;

        used[v] = true;
        ans = ans + w;

        for (auto [weight, u] : g[v]) {
            if (!used[u]) {
                edge.insert({weight, u});
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

//set не допускает дубликатов, поэтому если два ребра имеют одинаковый вес и ведут в одну вершину — второе не добавится. Это редкий случай, но лучше использовать multiset
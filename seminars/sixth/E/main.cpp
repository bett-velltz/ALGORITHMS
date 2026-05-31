#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <set>
#include <fstream>

using namespace std;
const int INF = INT_MAX;

vector<int> p;
vector<int> rang;
vector<tuple<string, int, int>> operations;
set<pair<int, int>> cut;

vector<pair<int, int>> edges;

int dsu_get(int v) {
    if (v == p[v])
        return v;
    return p[v] = dsu_get(p[v]);
}

void dsu_unite(int a, int b) {
    int x = dsu_get(a);
    int y = dsu_get(b);
    if (x != y) {
        if (rang[x] > rang[y])
            swap(x, y);
        p[x] = y;
        rang[y] += rang[x];
    }
}

int main() {
    ifstream file("input.txt");
    ofstream f("output.txt");

    int n, m, k;
    file >> n >> m >> k;
    p.resize(n);
    rang.resize(n, 1);
    for (int i = 0; i < n; i++) p[i] = i;

    for (int i = 0; i < m; ++i) {
        int u, v;
        file >> u >> v;
        --u, --v;
        edges.emplace_back(u, v);
    }

    for (int i = 0; i < k; ++i) {
        string s;
        int u, v;
        file >> s >> u >> v;
        --u, --v;
        operations.emplace_back(s, u, v);
        if (s == "cut") {
            cut.insert({u, v});
            cut.insert({v, u});
        }
    }

    for (int l = 0; l < m; ++l) {
        if (cut.find({edges[l].first, edges[l].second}) == cut.end()) {
            dsu_unite(edges[l].first, edges[l].second);
        }
    }

    reverse(operations.begin(), operations.end());
    vector<string> ans;

    for (int i = 0; i < k; ++i) {
        string s = get<0>(operations[i]);
        int u = get<1>(operations[i]);
        int v =  get<2>(operations[i]);
        if (s == "ask") {
            if (dsu_get(u) == dsu_get(v)) {
                ans.emplace_back("YES");
            } else {
                ans.emplace_back("NO");
            }
        } else {
            dsu_unite(u, v);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        f << ans[i] << '\n';
    }

    return 0;
}

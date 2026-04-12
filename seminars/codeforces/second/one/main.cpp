#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

void dfs(const string& name, int x, int& max_x, const map<string, vector<string>>& names, map<string, int>& c) {
    c[name] = 1;
    max_x = max(x, max_x);
    if (names.find(name) != names.end()) {
        for (const auto &u: names.at(name)) {
            if (c[u] == 0) {
                dfs(u, x + 1, max_x, names, c);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    map<string, vector<string>> d = {};
    for (int i = 0; i < n; ++i) {
        string name1;
        string name2;
        string reposted;
        cin >> name1 >> reposted >> name2;
        transform(name1.begin(), name1.end(), name1.begin(),
                  [](unsigned char c){ return std::tolower(c); });
        transform(name2.begin(), name2.end(), name2.begin(),
                  [](unsigned char c){ return std::tolower(c); });

        d[name2].emplace_back(name1) ;
    }
    map<string, int> color {};
    for (const auto& [key, value] : d) {
        color[key] = 0;
        for (const auto& v : value) {
            color[v] = 0;
        }
    }
    int res = 1;
    int max_res = 0;
    string polycarp = "polycarp";
    if (color.find(polycarp) != color.end()) {
        dfs(polycarp, res, max_res, d, color);
        res = max_res;
    }
    cout << res << '\n';
    return 0;
}
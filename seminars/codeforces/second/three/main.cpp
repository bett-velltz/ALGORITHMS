#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

bool dfs(int v, vector<int> &used, vector<vector<int>> &g, stack<int> &st) {

    used[v] = 1;
    for (auto u: g[v]) {
        if (used[u] == 1) {
            return false;
        }
        if (used[u] == 0) {
            if( !dfs(u, used, g, st)) {
                return false;
            };
        }
    }
    st.push(v);
    used[v] = 2;
    return true;
}


int main() {
    int n;
    cin >> n;
    vector<string> names(n);

    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    vector<vector<int>> m(26);
    vector<int> visited(26, 0);

    for(int i = 0; i < n-1; ++i) {
        string n1 = names[i];
        string n2 = names[i+1];

        int s = min(n1.size(), n2.size());
        bool same = true;

        for (int j = 0; j < s; ++j) {
            if (n1[j] != n2[j]) {
                m[static_cast<int>(n1[j]) - 97].emplace_back(static_cast<int>(n2[j]) - 97);
                same = false;
                break;
            }
        }

        if (same && n1.size() > n2.size()) {
            cout << "Impossible" << '\n';
            return 0;
        }
    }

    bool possible = true;
    stack<int> ans;

    for (int i = 0; i < 26; ++i) {
        if (visited[i] == 0) {
            if (!dfs(i, visited, m, ans)) {
                cout << "Impossible" << '\n';
                return 0;
            }
        }
    }

    while(!ans.empty()) {
        cout << static_cast<char>(ans.top()+97);
        ans.pop();
    }
    cout << '\n';
    return 0;
}
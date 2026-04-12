#include <iostream>
#include <vector>

using namespace std;

bool dfs(const vector<vector<int>> &m, const vector<int> &v, vector<int> &used, int u, int par) {
    used[u] = 1;
    for (auto l : m[u]) {
        if (v[u] != v[l]) continue;

        if (used[l] == 1) {
            if (l != par) {
                return true;
            }
        }
        if (used[l] == 0) {
            if (dfs(m, v, used, l, u)) {
                return true;
            }
        }
    }
    used[u] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    if (n < 2 || m < 2) {
        cout << "No";
        return 0;
    }

    vector<int> v (n*m, 0);
    vector<vector<int>> matrix (n*m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char letter;
            cin >> letter;
            v[i*m + j] = letter - 'a';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            int ind = i * m + j;
            if (i > 0) {
                matrix[ind].push_back((i - 1) * m + j);
            }
            if (i < n - 1) {
                matrix[ind].push_back((i + 1) * m + j);
            }
            if (j > 0) {
                matrix[ind].push_back(i * m + j - 1);
            }
            if (j < m - 1) {
                matrix[ind].push_back(i * m + j + 1);
            }
        }
    }

    vector<int> used (n*m, 0);

    for (int i = 0; i < n * m; ++i) {
            if (used[i] == 0) {
                if (dfs(matrix, v, used, i, -1)) {
                    cout << "Yes" << '\n';
                    return 0;
                }
            }
    }
    cout << "No" << '\n';
    return 0;
}
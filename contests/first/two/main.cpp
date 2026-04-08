#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n, 0));

    for (int j = 0; j < m; ++j) {
        int a, b;
        cin >> a >> b;
        v[a-1][b-1] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
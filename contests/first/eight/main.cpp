#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string ans = "Yes";
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int l = 0; l < m; ++l) {
        int i, j;
        cin >> i >> j;
        v[i-1][j-1] += 1;
        v[j-1][i-1] += 1;
    }
    for (int l = 0; l < n; ++l) {
        for (int j = l + 1; j < n; ++j) {
            if (v[l][j] != 1) {
                ans = "No";
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
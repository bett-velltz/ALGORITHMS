#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string ans = "Yes";
    vector<vector<int>> v(n, vector<int>(n, 0));

    for (int j = 0; j < m; ++j) {
        int a, b;
        cin >> a >> b;
        v[a-1][b-1] = 1;
        v[b-1][a-1] = 1;
    }

    for (int j = 0; j < n; ++j) {
        for (int l = 0; l < j; ++l) {
            if (v[j][l] == 0) {
                ans = "No";
            }
        }
        for (int l = j + 1; l < n; ++l) {
            if (v[j][l] == 0) {
                ans = "No";
            }
        }
    }
    cout << ans;
    return 0;
}
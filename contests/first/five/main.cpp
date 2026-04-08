#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int l = 0; l < m; ++l) {
        int i, j;
        cin >> i >> j;
        v[i-1][j-1] = 1;
        v[j-1][i-1] = 1;
    }
    for (int k = 0; k < n; ++k) {
        cout << accumulate(v[k].begin(), v[k].end(), 0) << ' ';
    }
    return 0;
}
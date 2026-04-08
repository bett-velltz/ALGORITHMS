#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }

    vector<int> col(n);
    for (int i = 0; i < n; ++i) {
        cin >> col[i];
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (v[i][j] == 1 && col[i] != col[j]) {
                ++res;
            }
        }
    }
    cout << res;
    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int minim = INT_MAX;
    vector<int> ans(3, 0);
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    //for (int i = 0; i < n; ++i) {
      //  for (int j = i + 1; j < n; ++j) {
        //    for (int l = j + 1; l < n; ++l) {
        // - если симметрична
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l) {
                if (i != j && j != l && l != i) {
                    int a = v[i][j] + v[j][l] + v[l][i];
                    if (a < minim) {
                        minim = a;
                        ans = {i + 1, j + 1, l + 1};
                    }
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
    return 0;
}
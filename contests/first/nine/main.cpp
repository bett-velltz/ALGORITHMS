#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ans(n);
    for (int i = 0; i < n; ++i) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            int a;
            cin >> a;
            ans[a-1].emplace_back(i+1);
        }
    }

    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        cout << ans[i].size() << ' ';
        for (int j = 0; j < ans[i].size(); ++j) {
                cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
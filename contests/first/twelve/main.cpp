#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        string l;
        getline(cin, l);
        l.erase(remove_if(l.begin(), l.end(), [](char c) { return c == ' '; }), l.end());
        for (int j = 0; j < l.length(); ++j) {
            ans[l[j] - '0' - 1][i] = 1;
        }
    }

    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            if (ans[i][j] == 1) {
                cout << j + 1 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
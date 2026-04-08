#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string res = "YES";

    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;
            v[i][j] = a;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
                for (int l = 0; l < n; ++l) {
                    if ((v[i][j] == 1 && v[j][l] == 1) && v[i][l] == 0) {
                        res = "NO";
                    }
                }
            }
        }
    cout << res;
    return 0;
}
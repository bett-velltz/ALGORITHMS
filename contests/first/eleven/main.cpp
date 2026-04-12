#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v (m, pair<int, int> (0, 0));
    vector<vector<int>> matrix (n+1, vector<int> (n+1, 0));

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        v[i].first = x;
        v[i].second = y;
        ++matrix[x][y];
    }

    long long res = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == j) continue;
            int a = v[i].first;
            int b = v[i].second;
            int c = v[j].first;
            int d = v[j].second;

            int two = matrix[b][c];
            int four = matrix[d][a];

            if ((a == b) && (c == b)) {
                --two;
            }
            if ((b == c) && (c == d)) {
                --two;
            }
            if ((d == c) && (a == d)) {
                --four;
            }
            if ((d == a) && (a == b)) {
                --four;
            }
            if ((b == d) && (a == c)) {
                res += (two - 1) * two;
            } else{
                res += two * four;
            }
        }
    }

    cout << res << '\n';
    return 0;
}
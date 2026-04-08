#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v (m, pair<int, int> (0, 0));
    vector<vector<int>> cnt(n, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> v[i].first >> v[i].second;
        ++cnt[v[i].first][v[i].second];
    }

    long long res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == j) continue;
                int A = v[i].first;
                int B = v[i].second;
                int C = v[j].first;
                int D = v[j].second;


                int b = cnt[B][C];
                int d = cnt[D][A];
                int bd = 0;
                if (B == D && C == A) {
                    bd = cnt[B][C];
                }
                int mid_res = b * d - bd;
                res += mid_res;
        }
    }

    cout << res << '\n';
    return 0;
}
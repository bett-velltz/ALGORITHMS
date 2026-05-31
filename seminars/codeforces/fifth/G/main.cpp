//
// Created by 1 on 18.05.2026.
//
#include <iostream>
#include <vector>

using namespace std;

int n, m, l;
vector<int> a_v;

int function() {
    int res = 0;
    for (int q = 0; q < n; ++q) {
        if (q == 0 && a_v[q] > l) {
            ++res;
        } else if (a_v[q] > l && a_v[q-1] <= l) {
            ++res;
        }
    }
    return res;
}

int main() {
    cin >> n >> m >> l;
    a_v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a_v[i];
    }
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            ans.emplace_back(function());
        } else {
            int p_i, d_i;
            cin >> p_i >> d_i;
            a_v[p_i-1] += d_i;
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}

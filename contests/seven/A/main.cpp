#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> st;
vector<long long> v;
vector<int> lg;

void build(int n) {
    st.resize(lg[n] + 1, vector<long long>(n));
    st[0] = v;

    for (int i = 1; i <= lg[n]; i++) {
        int len = 1 << (i - 1);
        for (int j = 0; j + (1 << i) - 1 < n; j++) {
            st[i][j] = max(st[i-1][j], st[i-1][j + len]);
        }
    }
}

long long get_max(int l, int r) {
    int level = lg[r - l + 1];
    long long len = 1 << level;
    return max(st[level][l], st[level][r - len + 1]);
}

int main() {
    int n;
    cin >> n;
    v.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    lg.resize(n + 1, 0);
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;

    build(n);
    vector<long long> res;
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        res.emplace_back(get_max(l, r));
    }
    for (int i = 0; i < k; ++i) {
        cout << res[i] << '\n';
    }
    return 0;
}
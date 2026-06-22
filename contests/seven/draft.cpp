#include <iostream>
#include <vector>
using namespace std;

long long mc(vector<int> &a, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2;
    long long cnt = mc(a, l, m) + mc(a, m, r);

    vector<int> e;
    int i = l, j = m;
    while (i < m && j < r) {
        if (a[i] <= a[j]) {
            e.push_back(a[i++]);
        } else {
            cnt += m - i;
            e.push_back(a[j++]);
        }
    }
    while (i < m) e.push_back(a[i++]);
    while (j < r) e.push_back(a[j++]);

    for (int k = l; k < r; ++k) a[k] = e[k - l];
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << mc(a, 0, n) << '\n';
    return 0;
}
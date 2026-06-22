#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        map<int, int> L, R;
        for (int i = 0; i < n; i++) {
            if (!L.count(a[i])) L[a[i]] = i;
            R[a[i]] = i;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (L[a[i]] != R[a[i]]) {
                cnt++;
                while (i + 1 < n && a[i + 1] == a[i]) i++;
            }
        }

        if (cnt <= 1) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}

int main() {
    solve();
    return 0;
}
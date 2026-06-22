#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

// dp[i] = максимум книжечек, если последнее посещённое мероприятие — i.

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> dp(n, 0);
    dp[0] = a[0];
    ll maxim = 0;
    for (int i = 1; i < n; ++i) {
        if (i - k - 1 >= 0) {
          maxim = max(maxim, dp[i-k-1]);
        }
        dp[i] = a[i] + maxim;
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long res = 0;
    vector<pair<long long, int>> v;
    for (int i = 0; i < n; ++i) {
        long long a;
        int b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    vector<long long> dp(n+1, 0);
    dp[n] = 0;
    for (int i = n-1; i >= 0; --i) {
        dp[i] = dp[i+1];
        int next_ind = min(n, i + v[i].second + 1);
        dp[i] = max(dp[i], v[i].first + dp[next_ind]);
    }
    cout << dp[0] << '\n';
    return 0;
}
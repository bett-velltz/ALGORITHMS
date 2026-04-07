#include <vector>
#include <iostream>
#include<set>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 3) {
        cout << 0;
        return 0;
    }
    long long res = 0;
    vector<int> v(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
    }
    long long sum_ = accumulate(v.begin(), v.end(), 0ll);
    if (sum_ % 3 != 0) {
        cout << 0;
        return 0;
    }
    int sum = sum_ / 3;

    vector<int> pref(n);
    for (size_t i = 0; i < n; ++i) {
        if (i == 0) {
            pref[i] = v[i];
        } else {
            pref[i] = v[i] + pref[i-1];
        }
    }
    int cnt = 0;
    for (int j = 0; j < n-1; ++j) {
        if (pref[j] == 2*sum) {
            res += cnt;
        }
        if (pref[j] == sum) {
            ++cnt;
        }
    }
    cout << res << '\n';
    return 0;
}
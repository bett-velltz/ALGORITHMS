//
// Created by Betty on 22.06.2026.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ll p, mod;
    cin >> p >> mod;
    string s;
    cin >> s;
    auto n = s.size();
    vector<ll> pref(n);
    pref[0] = (s[0] - 'a' + 1) % mod;

    for (auto i = 1; i < n; ++i) {
        pref[i] = (pref[i-1] * p +  (s[i] - 'a' + 1)) % mod;
    }

    for (int i = 0; i < n; ++i) {
        cout << pref[i] << '\n';
    }
    return 0;
}
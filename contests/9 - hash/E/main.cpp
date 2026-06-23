//
// Created by Betty on 22.06.2026.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
int base = 131;
ll mod = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    vector<ll> pref(s.size() + 1);
    pref[0] = 0;
    vector<ll> rev_pref(s.size() + 1);
    rev_pref[0] = 0;

    vector<ll> pw(s.size() + 1);
    pw[0] = 1;
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());

    for (auto i = 0; i < s.size(); ++i) {
        pref[i+1] = (pref[i] * base % mod + (s[i] - 'a' + 1)) % mod;
        rev_pref[i+1] = (rev_pref[i] * base % mod + (rev_s[i] - 'a' + 1)) % mod;
        pw[i+1] = (pw[i] * base) % mod;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        auto h1 = (pref[r] - pref[l-1] * pw[r-l+1] % mod + mod) % mod;
        auto h2 = (rev_pref[s.size()-l+1] - rev_pref[s.size()-r] * pw[r-l+1] % mod + mod) % mod;
        if (h1 == h2) {
            cout << '+';
            continue;
        }
        cout << '-';
    }
    return 0;
}
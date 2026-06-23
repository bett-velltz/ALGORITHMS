// Created by Betty on 22.06.2026.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

auto get_hash(const vector<ll> &pw, const vector<ll> &pref, const int l, const int r, const ll mod) {
    return (pref[r+1] - pref[l] * pw[r-l+1] % mod + mod) % mod;
}

int main() {
    int base = 131;
    ll mod = 1e9 + 7;

    string s;
    int q;
    cin >> s >> q;
    auto n = s.size();

    //считаем префиксные хэши
    vector<ll> pref(n+1);
    pref[0] = 0;
    vector<ll> pw(n+1);
    pw[0] = 1;

    for (auto i = 0; i < n; ++i) {
        pref[i+1] = (pref[i] * base + (s[i] - 'a' + 1)) % mod;
        pw[i+1] = (pw[i] * base) % mod;
    }

    for (int i = 0; i < q; ++i) {
        int l, a, b;
        cin >> l >> a >> b;
        if (get_hash(pw, pref, a, a + l - 1, mod) == get_hash(pw, pref, b, b + l - 1, mod)) {
            cout << 0 << '\n';
            continue;
        }
        //равосторонний бинпоиск по K
        int left = 0, right = l;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (get_hash(pw, pref, a, a + mid - 1, mod) == get_hash(pw, pref, b, b + mid - 1, mod)) {
                left = mid;
            } else right = mid - 1;
        }

        cout << (s[a + left] < s[b + left] ? -1 : 1) << '\n';
    }
    return 0;
}
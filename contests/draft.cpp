//
// Created by Betty on 22.06.2026.
//

#include <iostream>
#include <vector>
#include <unordered_set> //нам не нужно упорядоивание, а обычный сет работает медленно из-за него

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int base = 911382323;
    ll mod =  1e18 + 3;

    unordered_set<ll> s;
    vector<ll> hsh(n+2);
    hsh[1] = 0;

    for (int i = 1; i <= n; ++i) {
        int p;
        char c;
        cin >> p >> c;
        hsh[i+1] = (hsh[p] * base % mod + (c - 'a' + 1)) % mod;
        s.insert(hsh[i+1]);

        cout << s.size() << '\n';
    }

    return 0;
}
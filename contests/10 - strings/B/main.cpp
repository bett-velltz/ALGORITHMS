//
// Created by 1 on 23.06.2026.
//


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pref(n, 0);

    int k;
    for (int i = 1; i < n; ++i) {
        k = pref[i - 1];

        while (k > 0 && s[i] != s[k]) {
            k = pref[k - 1];
        }

        if (s[i] == s[k]) {
            pref[i] = k + 1;
        }
    }
    if (n % (n - pref[n-1]) == 0) {
        cout << (n - pref[n-1]) << '\n';
    } else {
        cout << n << '\n';
    }
    return 0;
}
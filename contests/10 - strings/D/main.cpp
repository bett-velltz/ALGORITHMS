//
// Created by 1 on 23.06.2026.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string str;
    cin >> str;

    string s = "#";
    for (char c : str) {
        s += c;
        s += "#";
    }

    int n = s.size();
    int C = 0, R = 0;
    vector<int> P(n, 0);

    for (int i = 0; i < n; ++i) {
        if (i < R) {
            P[i] = min(R - i - 1, P[2 * C - i]);
        }
        while (i - P[i] - 1 >= 0 && i + P[i] + 1 <= n - 1 && s[i - P[i] - 1] == s[i + P[i] + 1]) {
            P[i]++;
        }

        if (i + P[i] + 1 > R) {
            C = i;
            R = i + P[i] + 1;
        }
    }

    long long ans = 0;
    for (auto p : P) {
        ans += p/ 2;
    }

    cout << ans << '\n';
    return 0;
}
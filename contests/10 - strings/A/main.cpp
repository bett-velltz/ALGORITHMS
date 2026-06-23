//
// Created by Betty on 23.06.2026.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string substr, st;
    cin >> substr >> st;

    int n = substr.size() + st.size() + 1;
    string s = substr + '$' + st;

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
    int cnt = 0;
    vector<int> ans;
    for (int i = substr.size()+1; i < n; ++i) {
        if (pref[i] == substr.size()) {
           ++cnt;
           ans.emplace_back(i - 2*substr.size() + 1);
        }
    }

    cout << cnt << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}
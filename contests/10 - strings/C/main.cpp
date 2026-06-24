//
// Created by 1 on 23.06.2026.
//


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string rev_s  = s;
    reverse(rev_s.begin(), rev_s.end());

    string main_str = s + '$' + rev_s;
    int m = main_str.size();
    vector<int> z(m, 0);

    int l = 0, r = 0;
    for (int i = 1; i < m; ++i) {
        z[i] = max(0, min(r - i, z[i - l]));

        while (i + z[i] < m && main_str[i + z[i]] == main_str[z[i]]) {
            z[i]++;
        }

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }

    for (int i = 1; i <= n; ++i) {

        int p = (n + 1) + (n - i);

        cout <<  z[p] << ' ';
    }



    return 0;
}
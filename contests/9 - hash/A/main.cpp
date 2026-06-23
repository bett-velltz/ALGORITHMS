//
// Created by 1 on 21.06.2026.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "lllllzzzzz";

    for (int i = 0; i < n; ++i) {
        cout << s << '\n';
        next_permutation(s.begin(), s.end());
    }
    return 0;
}
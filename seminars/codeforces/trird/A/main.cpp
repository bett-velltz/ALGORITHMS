#include <iostream>
#include <set>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r;

    for (int i = l; i < r + 1; ++i) {
        set<char> s {};
        string word = to_string(i);
        for (char c : word) {
            s.insert(c);
        }
        if (s.size() == word.length()) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}

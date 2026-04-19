#include <iostream>
#include <algorithm>

//лина максимального интервала из L + 1

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;

        int a = 0;
        int maximum = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'L') {
                ++a;
                maximum = max(maximum, a);
            } else {
                a = 0;
            }
        }
        cout << maximum + 1 << '\n';
    }

    return 0;
}
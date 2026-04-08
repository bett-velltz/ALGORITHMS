#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        if (n < 2) {
            cout << '0' << '\n';
            break;
        }
        vector<int> d(n);

        for (int j = 0; j < n; ++j) {
            cin >> d[j];
        }
        sort(d.begin(), d.end(), std::greater<int>());

        vector<int> pref(n);
        for (int j = 0; j < n; ++j) {
            if (j == 0) {
                pref[j] = 0;
            } else {
                pref[j] = pref[j-1] + d[j-1];
            }
        }
        int res = 0;
        for (int j = 0; j < n; ++j) {
            res += d[j];
            res -= pref[j];
        }
        cout << res << '\n';
    }
    return 0;
}
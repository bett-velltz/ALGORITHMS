#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<long long> v(n);

        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }
        set<int> v_set(v.begin(), v.end());
        if (v_set.size() == 1) {
            cout << "NO" << '\n';
        } else {
            int center_ind = 0;
            int center_band = v[0];

            int l = 0;
            while (l < n-1 && v[l] == center_band) {
                ++l;
            }

            cout << "YES" << '\n';
            for (int j = 1; j < n; ++j) {
                if (v[j] != center_band) {
                    cout << center_ind + 1 << ' ' << j + 1 << '\n';
                } else {
                    cout << l + 1 << ' ' << j + 1 << '\n';
                }
            }
        }
    }
}
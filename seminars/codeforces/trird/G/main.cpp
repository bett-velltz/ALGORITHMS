#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int mine = (accumulate(a.begin(), a.end(), 0) + 1) / 2;
    if (mine == accumulate(a.begin(), a.end(), 0) / 2) {
        ++mine;
    }
    int ans = 0;
    while (ans <= n) {
        if (accumulate(a.begin(), a.begin() + ans, 0) < mine) {
            ++ans;
            continue;
        }
        cout << ans << '\n';
        break;

    }
    return 0;
}
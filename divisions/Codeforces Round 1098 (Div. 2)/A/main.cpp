#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> answer;
    for (int i = 0; i < t; ++i) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        int n;
        cin >> n;

        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            if (x == 0) cnt0++;
            else if (x == 1) cnt1++;
            else cnt2++;
        }
        int ans = cnt0;
        int pairs = min(cnt1, cnt2);
        ans += pairs;
        cnt1 -= pairs;
        cnt2 -= pairs;
        ans += cnt1 / 3;
        ans += cnt2 / 3;

        answer.emplace_back(ans);
    }

    for (int i = 0; i < t; ++i) {
        cout << answer[i] << '\n';
    }
    return 0;
}
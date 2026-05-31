#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<long long> answer;
    for (int i = 0; i < t; ++i) {
        long long n, x_1, x_2, k;
        cin >> n >> x_1 >> x_2 >> k;

        long long len = min(abs(x_1 - x_2), n - abs(x_1 - x_2));
        long long ans = min(k + len, n - len);
        answer.emplace_back(ans);
    }
    for (int i = 0; i < t; ++i) {
        cout << answer[i] << '\n';
    }
    return 0;
}
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

long long best;
long long a_val;
int D[2];

void solve(int len, int pos, long long cur) {
    if (cur - a_val >= best) return;
    if (pos == len) {
        best = min(best, abs(a_val - cur));
        return;
    }
    for (int i = 0; i < 2; i++) {
        if (pos == 0 && D[i] == 0 && len > 1) continue;
        solve(len, pos + 1, cur * 10 + D[i]);
    }
}

int main() {

    int t;
    cin >> t;
    vector<long long> answer;
     for (int i = 0; i < t; ++i) {
        long long n;
        cin >> a_val >> n;
        cin >> D[0] >> D[1];

        best = LLONG_MAX;
        for (int len = 1; len <= 18; len++) {
            solve(len, 0, 0);
        }
        answer.emplace_back(best);
    }
    for (int i = 0; i < t; ++i) {
        cout << answer[i] << '\n';
    }
    return 0;
}
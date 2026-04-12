#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    int s = 0;
    vector<pair<int, int>> pairs;
    vector<pair<int, int>> ans;
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s += a;
        if (a == 1) {
            q.push(i);
        } else {
            pairs.emplace_back(i, a);
        }
    }

    if ((s != 2 * (n - 1)) || q.size() < 2) {
        cout << "NO" << '\n';
        return 0;
    }

    //cout << "YES" << '\n';
    while (!q.empty() && !pairs.empty()) {
        int x = q.front();
        q.pop();
        ans.emplace_back(x+1, pairs.back().first + 1 );

        --pairs.back().second;
        if (pairs.back().second == 1) {
            q.push(pairs.back().first);
            pairs.pop_back();
        }
    }
    if (q.size() == 2 && pairs.empty()) {
        int u = q.front();
        q.pop();
        int v = q.front();
        q.pop();
        ans.emplace_back(u + 1, v + 1);
    } else if (!q.empty() || !pairs.empty()) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    for (const auto& an : ans) {
        cout << an.first << ' ' << an.second << '\n';
    }

    return 0;
}
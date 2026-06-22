#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> m;
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (!st.empty()) {
            m.push_back(st.top());
            m.push_back(i);
            st.pop();
        }
    }

    string ans(n, '0');
    int rem = min(k, (int)m.size());

    for (int i = 0; i < rem; ++i) {
        ans[m[i]] = '1';
    }

    cout << ans << "\n";
}

int main() {


    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
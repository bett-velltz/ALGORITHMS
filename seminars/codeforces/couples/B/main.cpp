#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int summa = 0;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> s[i];
        summa += s[i];
    }
    sort(s.begin(), s.end());
    int res = summa - s[0];
    cout << res << '\n';
    return 0;
}
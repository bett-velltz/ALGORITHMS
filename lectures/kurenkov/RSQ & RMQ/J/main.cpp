#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        v[a]++;
        v[b]++;
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i]%2 == 1) {
            ++k;
        }
    }
    int ans = k / 2 - 1;;
    cout << max(0, ans) << '\n';
    return 0;
}
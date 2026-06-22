#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    if (n > 20) {
        cout << "TOO HARD" << '\n';
        return 0;
    }
    ll res = 1;
    int i = 0;
    while (i < n) {
        res *= 2;
        ++i;
        if (res > 1e6) {
            cout << "TOO HARD" << '\n';
            return 0;
        }
    }
    cout << res << '\n';
    return 0;
}


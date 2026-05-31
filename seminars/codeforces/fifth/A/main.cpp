#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << '0' << '\n';
        return 0;
    }
    n -= 2;
    int ans = (n + 1) / 2;
    cout << ans << '\n';
    return 0;
}

//(x + y - 1) / y;  - целочисленное округление вверх
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int s = a + b + c + d;
    if (s % 2 != 0) {
        cout << "NO" << '\n';
        return 0;
    }
    if ((a + b == c + d) || (a + d == c + b) || (a + c == b +d)) {
        cout << "YES" << '\n';
        return 0;
    }
    cout << "NO" << '\n';
    return 0;
}
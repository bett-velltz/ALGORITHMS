#include <iostream>
using namespace std;
#include <cmath>

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        double n, x, y, z;
        cin >> n >> x >> y >> z;
        double first;
        double second;
        first = (n / (x + y));
        if (z * x >= n) {
            second = n/x;
        } else {
            second = z + ((n - z*x)/(x + 10*y));
        }
        double res = min(first, second);
        cout << ceil(res) << '\n';
    }
    return 0;
}
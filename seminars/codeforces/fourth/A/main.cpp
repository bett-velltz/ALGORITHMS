#include <iostream>
#include <numeric>
using namespace std;

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    long long n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;

    long long ans = 0;

    if (a == b) {
        if (p >= q) {
            ans += p * (n / a);
        } else {
            ans += q * (n / a);
        }
    }
    else {
        long long step = lcm(a, b);
        if (p >= q) {
            ans += p * (n / step);
        } else {
            ans += q * (n / step);
        }

        ans += p * ((n / a) - (n / step));
        ans += q * ((n / b) - (n / step));
    }

    cout << ans << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i * i == n) {
                res++;
            } else {
                res += 2;
            }
        }
    }
    cout << res-1 << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    long long a_c = a, b_c = b;
    while (b > a) {
        if (b % 2 == 0) {
            b /= 2;
        } else if (b % 10 == 1) {
            b -= 1;
            b /= 10;
        } else break;
    }
    if (b == a) {
        cout << "YES" << '\n';
        vector<long long> res;
        res.emplace_back(b_c);
        while (b_c > a_c) {
            if (b_c % 2 == 0) {
                b_c /= 2;
            } else if (b_c % 10 == 1) {
                b_c -= 1;
                b_c /= 10;
            } else break;
            res.emplace_back(b_c);
        }
        cout << res.size() << '\n';
        for (int l = res.size()-1; l >= 0; --l) {
            cout << res[l] << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int sq = n * n;
    if (sq % k == 0) {
        cout << "YES" << '\n';
        return 0;
    }
    cout << "NO" << '\n';
    return 0;
}
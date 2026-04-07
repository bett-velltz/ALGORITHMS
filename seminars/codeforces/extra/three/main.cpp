#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> res(n);
        int l = 1;
        for (int i = 0; i < 3*n; i += 3) {
            res[i] = l;
            ++l;
        }
        int k = n + 1;
        for (int i = 1; i < 3*n; i += 3) {
            res[i] = k;
            res[++i] = ++k;
            --k;
        }

    }

    return 0;
}
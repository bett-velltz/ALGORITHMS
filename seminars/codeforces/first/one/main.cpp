#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> d(n);

        for (int j = 0; j < n; ++j) {
            cin >> d[j];
        }
    }
    return 0;
}
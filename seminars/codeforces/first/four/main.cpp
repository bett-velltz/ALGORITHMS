#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int one = 0;
    int two = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            ++one;
        } else {
            ++two;
        }
    }

    if (one == n) {
        for (int i = 0; i < n; ++i) {
            cout << '1' << ' ';
        }
    }
    else if (two == n) {
        for (int i = 0; i < n; ++i) {
            cout << '2' << ' ';
        }
    } else {
        cout << "2 1 ";
        for (int i = 0; i < two - 1; ++i) {
            cout << '2' << ' ';
        }
        for (int i = 0; i < one - 1; ++i) {
            cout << '1' << ' ';
        }
    }
    return 0;
}
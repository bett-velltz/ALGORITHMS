#include <vector>

#include <iostream>
using namespace std;

int main() {
    string res = "NO";
    int n;
    cin >> n;
    vector<int> planes(n);

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        planes[i] = a;
    }
    for (int i = 1; i < n + 1; ++i) {
        if (planes[planes[planes[i-1]-1]-1] == i) {
            res = "YES";
            break;
        }
    }
    cout << res;
    return 0;
}
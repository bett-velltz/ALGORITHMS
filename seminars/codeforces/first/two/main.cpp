#include <vector>

#include <iostream>
using namespace std;


int main() {

    int n, s;
    string res = "NO";
    cin >> n >> s;
    vector<int> first(n);
    vector<int> second(n);

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        first[i] = m;
    }

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        second[i] = m;
    }

    if (first[0] != 0) {
        if (first[s-1] == 1) {
            res = "YES";
        }
        else if (first[s-1] == 0 && second[s-1] != 0) {
            int i = s-1;
            while (i < n - 1) {
                ++i;
                if (first[i] == 0 || second[i] == 0) {
                    continue;
                } else {
                    res = "YES";
                    break;
                }
            }
        }

    }

    if (s == 1) {
        res = "NO";
    }
    cout << res;
    return 0;
}
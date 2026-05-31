//C. Саратовская дилемма
//https://codeforces.com/group/NvH0Eve9m2/contest/695479/problem/C

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> yes, no, alone(a);
    vector<pair<int, int>> couples(b, {0, 0});

    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            no.emplace_back(i+1);
        } else {
            yes.emplace_back(i+1);
        }
    }
    if (n > a + 2*b) {
        cout << "NO" << '\n';
        return 0;
    }

    //заполняю всех кто хочет один
    int free_a = a;
    int free_b = b;
    int i = 0;

    while (i < (int)no.size() && free_a > 0) {
        alone[a-free_a] = (no[i]);
        ++i;
        --free_a;
    }
    while (i < (int)no.size() && free_b > 0) {
        couples[b-free_b].first = (no[i]);
        ++i;
        --free_b;
    }
    if (i < (int)no.size()) {
        cout << "NO" << '\n';
        return 0;
    }
    //размещаю оставшихся
    i = 0;
    while (i < (int)yes.size() && free_a > 0) {
        alone[a-free_a] = yes[i];
        ++i;
        --free_a;
    }

    for (int j = 0; j < b && i < (int)yes.size(); ++j) {
        if (couples[j].first != 0) {
            continue;
        }
        couples[j].first = yes[i];
        ++i;
        if (i < (int)yes.size()) {
            couples[j].second = yes[i];
            ++i;
        }
    }

    if (i < (int)yes.size()) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    for (int el : alone) {
        cout << el << '\n';
    }
    for (auto [u, v] : couples) {
        cout << u << ' ' << v << '\n';
    }

    return 0;
}
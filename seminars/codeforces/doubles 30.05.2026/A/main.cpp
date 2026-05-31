#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    long double s = 0;
    vector<long double> res;
    multiset<long double> m;

    for (int i = 0; i < n; ++i) {
        long double num;
        char sign;
        cin >> sign >> num;
        if (sign == '-') {
            s -= num;
            auto ind = m.find(num);
            m.erase(ind);
        } else {
            s += num;
            m.insert(num);
        }
        if (m.size() == 0) {
            res.emplace_back(0);
            continue;
        }
        res.emplace_back(s/m.size());
    }
    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(9) << res[i] << '\n';
    }
    return 0;
}
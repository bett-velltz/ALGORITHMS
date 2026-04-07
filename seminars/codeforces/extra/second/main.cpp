
//сложить все с (-1), максимум из начального и его оставляем (добавляем *2)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int res = 0;
        vector<int> numb(7);
        for (int j = 0; j < 7; ++j) {
            int a;
            cin >> a;
            numb[j] = a;
            res -= a;
        }
        auto it = max_element(numb.begin(), numb.end());
        int m = *it;
        res += 2 * m;
        cout << res << '\n';
    }

    return 0;
}
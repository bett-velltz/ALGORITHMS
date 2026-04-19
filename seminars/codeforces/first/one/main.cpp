//ответ = максимальное число в списке (сумма всех положительных дорожек) +  для каждого числа вычитаем (его порядковый номер количество) раз и прибавляем остальное количество раз относительно количества вершины (та как отрицательный весь - это все s[i]-s[j] в списке, где i меньше j)


#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<long long> d(n);

        for (int j = 0; j < n; ++j) {
            cin >> d[j];
        }
        if (n < 2) {
            cout << '0' << '\n';
            continue;
        }
        sort(d.begin(), d.end());

        long long res = d.back();
        for (int j = 0; j < n; ++j) {
            res += d[j] * (n - 1 - 2 * j);
        }
        cout << res << '\n';
    }
    return 0;
}
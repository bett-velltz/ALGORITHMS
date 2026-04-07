#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    long long pref = 0;
    long long parts = 0;
    long long ans = 0;
    long long cnt = 0;
    if (sum % 3 != 0) {
        std::cout << "0";
        return 0;
    }
    parts = sum / 3;
    for (int i = 0; i < n-1; ++i) {
        pref += v[i];
        if (pref == 2 * parts) {
            ans += cnt;
        }
        if (pref == parts) {
            cnt++;
        }
    }
    std::cout << ans << std::endl;
}
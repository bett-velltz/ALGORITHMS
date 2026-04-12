#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long t;
    cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int left = 0;
    int curr = 0;
    int max_count = 0;

    for (int right = 0; right < n; ++right) {
        curr += v[right];

        while (curr > t) {
            curr -= v[left];
            ++left;
        }

        max_count = max(max_count, right - left + 1);
    }

    cout << max_count;
    return 0;
}
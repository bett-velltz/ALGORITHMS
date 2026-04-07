#include <vector>
#include <iostream>
#include<set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> people(2*n);
    vector<int> variants;

    for (int i = 0; i < 2*n; ++i) {
        int a;
        cin >> a;
        people[i] = a;
    }

    for (int i = 0; i < 2*n; ++i) {
        for (int j = i + 1; j < 2*n; ++j) {
            auto m_copy  = people;
            m_copy.erase(m_copy.begin() + i);
            m_copy.erase(m_copy.begin() + j-1);
            sort(m_copy.begin(), m_copy.end());
            int x = 0;
            for (int l = 0; l < 2*n-2; l+=2) {
                x += m_copy[l+1] - m_copy[l];
            }
            variants.push_back(x);
        }
    }
    auto minimum = min_element(variants.begin(), variants.end());
    auto answer = *minimum;
    cout << answer;
    return 0;
}
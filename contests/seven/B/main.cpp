#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v;

int main() {
    int n;
    cin >> n;
    v.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n-1; ++i) {
        int x;
        cin >> x;
        --x;
        v[x].emplace_back(i);
    }
    return 0;
}
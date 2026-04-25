#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> v;

int main () {
    int n, m;
    cin >> n >> m;
    v.resize(n);

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a-1].emplace_back(b-1, w);
        v[b-1].emplace_back(a-1, w);
    }
}
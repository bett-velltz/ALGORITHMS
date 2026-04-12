#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (n, 0));

    for (int i = 0; i < m; ++i) {
        int a_i, b_i;
        cin >> a_i >> b_i;
        v[a_i-1][b_i-1] = 1;
        v[b_i-1][a_i-1] = 1;
    }
    return 0;
}


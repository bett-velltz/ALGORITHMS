#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> a;
int ans = 0;
int n, m;
vector<int> count;

void dfs(int u, int p, int cats) {
   if (a[u] == 1) {
       ++cats;
   } else {
       cats = 0;
   }
   if (cats > m) return;

   for (auto w : v[u]) {
       if (w != p) {
           dfs(w, u, cats);
       }
   }
    if (v[u].size() == 1 && u != 0) {
        ++ans;
    }
}

int main() {
    cin >> n >> m;
    a.resize(n, 0);
    v.resize(n);
    count.resize(n);


    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < n-1; ++j) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }

    dfs(0, -1, 0);
    cout << ans << '\n';
    return 0;
}
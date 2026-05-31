
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200001;
int p[MAXN], r[MAXN], nxt[MAXN];

int dsu_get(int v) {
    if (p[v] == v) return v;
    p[v] = dsu_get(p[v]);
    return p[v];
}

void dsu_unite(int a, int b) {
    a = dsu_get(a);
    b = dsu_get(b);
    if (a == b) return;
    if (r[a] < r[b]) swap(a, b);
    p[b] = a;
    if (r[a] == r[b]) r[a]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        r[i] = 0;
        nxt[i] = i + 1;
    }

    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) {
            dsu_unite(x, y);
        } else if (type == 2) {
            int cur = x;
            while (cur <= y) {
                int tmp = nxt[cur];
                dsu_unite(x, cur);
                nxt[cur] = y + 1;
                cur = tmp;
            }
            nxt[x] = max(nxt[x], y + 1);
        } else {
            if (dsu_get(x) == dsu_get(y)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

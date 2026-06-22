#include <iostream>
#include <vector>
using namespace std;

vector<long long> t;
long long n, q;

long long sum(long long r) {
    long long res = 0;
    for (; r > 0; r -= r & -r)
        res += t[r];
    return res;
}
long long sum(long long l, long long r) {
    return sum(r) - sum(l - 1);
}

// прибавляет x к элементу с индексом k
void add(int k, long long x) {
    for (; k <= n; k += k & -k)
        t[k] += x;
}

int main() {
    cin >> n >> q;
    t.resize(n+2, 0);

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        add(i, a[i] - a[i - 1]);
    }


    vector<long long> res;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int r, l;
            long long x;
            cin >> l >> r >> x;
            add(l, x);
            add(r + 1, -x);
        }
        else {
            int ind;
            cin >> ind;
            res.emplace_back( sum(ind));
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << '\n';
    }
    return 0;
}
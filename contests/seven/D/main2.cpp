#include <iostream>
#include <vector>
using namespace std;

struct SegTree {
    int N = 1;
    vector<long long> t, vec;

    SegTree(const vector<int> &a) {
        while (N < (int)a.size()) N *= 2;
        t.assign(2 * N, 0);
        vec.assign(2 * N, 0);

        for (int i = 0; i < (int)a.size(); ++i)
            t[i + N] = a[i];

        for (int i = N - 1; i > 0; --i)
            t[i] = max(t[2*i], t[2*i+1]);
    }

    void push(int v) {
        if (vec[v] != 0) {
            for (int c : {2*v, 2*v+1}) {
                t[c] += vec[v];
                vec[c] += vec[v];
            }
            vec[v] = 0;
        }
    }

    void add(int v, int tl, int tr, int l, int r, long long x) {
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            t[v] += x;
            vec[v] += x;
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        add(2*v,   tl, tm, l, r, x);
        add(2*v+1, tm, tr, l, r, x);
        t[v] = max(t[2*v], t[2*v+1]);
    }

    long long get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) {
            return 0;
        }
        if (tl >= l && tr <= r) {
            return t[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        return max(get(2*v, tl, tm, l, r), get(2*v+1, tm, tr, l, r));
    }

    void add(int l, int r, long long x) {
        add(1, 0, N, l, r, x);
    }
    long long get(int l, int r){
        return get(1, 0, N, l, r);
    }
};

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    SegTree seg(v);

    int m;
    cin >> m;
    bool first = true;

    for (int i = 0; i < m; ++i) {
        char type;
        cin >> type;
        if (type == 'm') {
            int l, r;
            cin >> l >> r;

            cout << seg.get(l-1, r) << '\n';
        } else {
            int l, r, add;
            cin >> l >> r >> add;
            seg.add(l-1, r, add);
        }
    }
    cout << '\n';
    return 0;
}
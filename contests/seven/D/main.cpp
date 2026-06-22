#include <iostream>
#include <vector>
using namespace std;

struct SegTree {
    int N = 1;
    vector<long long> t;

    SegTree(const vector<int> &a) {
        //получение степени 2
        while (N < a.size()) {
            N *= 2;
        }
        t.resize(2 * N, 0);

        //заполнение элементами массива
        for (int i = 0; i < a.size(); ++i) {
            t[i + N] = a[i];
        }

        //построение предков
        for (int i = N - 1; i > 0; --i) {
            t[i] = t[2 * i + 0] + t[2 * i + 1];
        }
    }

    long long get(int v, int tl, int tr, int l, int r) {
        if (tl >= r || tr <= l) {
            return 0;
        }

        if (tl >= l && tr <= r) {
            return t[v];
        }

        int tm = (tl + tr) / 2;

        return get(v * 2 + 0, tl, tm, l, r) + get(v * 2 + 1, tm, tr, l, r);
    }

    long long get(int l, int r) {
        return get(1, 0, N, l, r);
    }

    void update_low(int p, long long x) {
        p += N;
        t[p] = x;
        p /= 2;
        while (p > 0) {
            t[p] = t[2 * p + 0] + t[2 * p + 1];
            p /= 2;
        }
    }


    void update_high(int v, int tl, int tr, int p, long long x) {
        if (tl > p || tr <= p) {
            return;
        }
        if (tl + 1 == tr) {
            // v == p + N
            t[v] = x;
            return;
        }

        int tm = (tl + tr) / 2;
        update_high(2 * v + 0, tl, tm, p, x);
        update_high(2 * v + 1, tm, tr, p, x);
        t[v] = t[2 * v + 0] + t[2 * v + 1];
    }

    void update_high(int p, long long x) {
        update_high(1, 0, N, p, x);
    }


};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int m;
    cin >> m;
    vector<int> res;
    for (int i = 0; i < m; ++i) {
        char type;
        cin >> type;
        if (type == 'm') {
            int l, r;
            cin >> l >> r;
        } else {
            int l, r, add;
            cin >> l >> r >> add;
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << '\n';
    }
    return 0;
}
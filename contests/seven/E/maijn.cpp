#include <iostream>
#include <vector>
using namespace std;

vector<long long> t;
int N, M;

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
    for (; k <= N; k += k & -k)
        t[k] += x;
}

int main() {
    cin >> N >> M;
    t.resize(N+1, 0);

    for (int i = 1; i <= N; ++i) {
        long long x;
        cin >> x;
        add(i, x);
    }


    vector<long long> res;
    for (int i = 0; i < M; ++i) {
        int r, l;
        cin >> l >> r;
        res.emplace_back(sum(l, r));
    }
    for (int i = 0; i < M; ++i) {
        cout << res[i] << '\n';
    }
    return 0;
}
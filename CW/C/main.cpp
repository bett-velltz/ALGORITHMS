#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> v;

int func(int const &A, int const &B) {
    if (A == 1 || B == 1) {
        return 1;
    }
    set<int> vis;

    vis.insert(A);
    int i = A;
    while (i != 1) {
        vis.insert(v[i-2]);
        i = v[i-2];
    }

    int j = B;
    while (true) {
        if (vis.find(j) != vis.end()) {
            break;
        }
        j = v[j-2];
    }
    return j;
}

int main() {
    int N;
    cin >> N;
    int A, B;
    cin >> A >> B;
    v.resize(N-1);
    for (int i = 0; i < N-1; ++i) {
        cin >> v[i];
    }
    cout << func(A, B) << '\n';
    return 0;
}
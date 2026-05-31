#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

vector<int> p;
vector<int> rang;
vector<long long> saving;

int dsu_get(int v) {
    if (v == p[v]) {
        return v;
    }
    int par = p[v];
    int r = dsu_get(par);
    saving[v] += saving[par];
    p[v] = r;
    return r;
}

void dsu_unite(int a, int b) {
    int x = dsu_get(a);
    int y = dsu_get(b);
    if (x != y) {
        if (rang[x] > rang[y]) {
            swap(x, y);

        p[x] = y;
        rang[y] += rang[x];
        saving[x] -= saving[y];
    }
}


int main() {
    ifstream file("input.txt");

    int n, m;
    file >> n >> m;

    p.resize(n);
    rang.resize(n, 1);
    saving.resize(n, 0);

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    vector<long long> ans;

    for (int i = 0; i < m; ++i) {
        string word;
        file >> word;
        if (word == "join") {
            int x, y;
            file >> x >> y;
            --x, --y;
            dsu_unite(x, y);
        }
        else if (word == "add") {
            int x, v;
            file >> x >> v;
            --x;
            int x_par = dsu_get(x);
            saving[x_par] += v;
        }
        else {
            int x;
            file >> x;
            --x;
            dsu_get(x);
            ans.emplace_back(saving[x]);
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
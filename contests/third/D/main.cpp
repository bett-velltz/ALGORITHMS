#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<long long> times;
vector<vector<int>> details;
vector<vector<int>> rev_g;

vector<int> order;
vector<int> color;
vector<bool> required;

void dfs(int ver) {
    color[ver] = 1;
    for (auto u : details[ver]) {
        if (required[u] && color[u] == 0) {
            dfs(u);
        }
    }

    color[ver] = 2;
    order.emplace_back(ver+1);
}

void dfs_required(int ver) {
    required[ver] = true;
    for (auto u : rev_g[ver]) {
        if (!required[u]) {
            dfs_required(u);
        }
    }
}

int main () {
    int n;
    cin >> n;
    times.resize(n);
    details.resize(n);
    rev_g.resize(n);
    color.resize(n, 0);
    required.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int d;
            cin >> d;
            details[d-1].emplace_back(i);
            rev_g[i].emplace_back(d-1);
        }
    }

    dfs_required(0);

    for (int i = 0; i < n; ++i) {
        if (required[i] && color[i] == 0) {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());

    int cnt = 0;
    long long ans_time = 0;
    for (int i = 0; i < n; ++i) {
        if (required[i]) {
            ans_time += times[i];
            ++cnt;
        }
    }
    cout << ans_time << ' ' << cnt << '\n';
    for (int j = 0; j < order.size(); ++j) {
        cout << order[j] << ' ';
    }
    cout << '\n';

}
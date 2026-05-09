#include <iostream>
#include <vector>

using namespace std;
int INF = 1e9;

int main() {
    int N;
    cin >> N;
    vector<int> dist(N, 0);
    vector<vector<int>> gr(N, vector<int>(N, 0));
    vector<int> parent(N, -1);

    dist[0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> gr[i][j];
        }
    }

    for (int k = 0; k < N - 1; k++){
        bool is_updated = false;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int w = gr[i][j];

                if (dist[j] > dist[i] + w) {
                    dist[j] = dist[i] + w;
                    parent[j] = i;
                    is_updated = true;
                }
            }
        }
        if (!is_updated) break;
    }

    int cycle = -1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int w = gr[i][j];
            if (dist[i] + w < dist[j]) {
                cycle = j;
                break;
            }
        }
        if (cycle != -1) break;
    }

    if (cycle == -1) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < N; i++) {
        cycle = parent[cycle];
    }
    vector<int> ans;
    int cur = cycle;
    while (true) {
        ans.emplace_back(cur);
        cur = parent[cur];
        if (cur == cycle) break;
    }

    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i]+1 << ' ';
    }
    cout << '\n';

    return 0;
}
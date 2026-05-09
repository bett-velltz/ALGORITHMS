#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;
int INF = 1e9;

int main() {
    vector<vector<int>> gr;
    vector<int> dist;
    int N, M;
    cin >> N >> M;
    dist.resize(N, INF);
    dist[0] = 0;

    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        gr.push_back({a, b, w});
    }

    for (int k = 1; k < N - 1; k++){
        bool is_updated = false;
        for (auto l: gr) {
            int x = l[0];
            int y = l[1];
            int w = l[2];
            if (dist[x] != INF && dist[y] > dist[x] + w) {
                dist[y] = dist[x] + w;
                is_updated = true;
            }
        }
        if (!is_updated) break;
    }

    for (int i = 0; i < N; ++i) {
        if (dist[i] == INF) {
            cout << 30000 << ' ';
            continue;
        }
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}
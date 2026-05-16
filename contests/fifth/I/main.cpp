#include <iostream>
#include <vector>

using namespace std;
int INF = 1e9;

int main() {
    int N, M, K, S;
    cin >> N >> M >> K >> S;
    --S;
    vector<vector<pair<int, int>>> g(N);
    vector<vector<int>> dp(K+1, vector<int>(N, INF));
    dp[0][S] = 0;

    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        g[a].emplace_back(b, w);
    }

    for (int k = 1; k <= K; ++k) {
        for (int l = 0; l < N; ++l) {
            for (auto [to, weight] : g[l]) {
                //dp[k][to] = min(dp[k-1][to], dp[k][to]); оставляем если ищем просто наикратчайший путь, так как K тут значит, что пуит длины не бодьше К, а если ищем конкретную длину, так не делаем
                if (dp[k-1][l] == INF) continue;
                dp[k][to] = min(dp[k][to], dp[k-1][l] + weight);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (dp[K][i] == INF) {
            cout << -1 << '\n';
            continue;
        }
        cout << dp[K][i] << '\n';
    }

    return 0;
}
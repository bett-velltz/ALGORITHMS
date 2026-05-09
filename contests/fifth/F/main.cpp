#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    vector<vector<int>> gr;
    int N;
    cin >> N;
    gr.resize(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> gr[i][j];
        }
    }

    for (int k = 0; k < N; k++) {        //текущая вершина, используемая для улучшения
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << gr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
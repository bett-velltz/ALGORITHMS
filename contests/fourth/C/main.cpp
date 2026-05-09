#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, x_1, y_1, x_2, y_2;
    cin >> N >> x_1 >> y_1 >> x_2 >> y_2;
    --x_1, --y_1, --x_2, --y_2;

    vector<vector<int>> field(N, vector<int>(N, -1));
    int steps[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

    queue<pair<int, int>> q;

    q.push({x_1, y_1});
    field[x_1][y_1] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int x_n = x + steps[i][0];
            int y_n = y + steps[i][1];
            if (x_n < 0 || x_n >= N || y_n < 0 || y_n >= N) continue;
            if (field[x_n][y_n] == -1) {
                field[x_n][y_n] = field[x][y] + 1;
                q.push({x_n, y_n});
            }
        }
    }

    cout << field[x_2][y_2] << '\n';
    return 0;
}
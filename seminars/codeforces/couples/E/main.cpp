#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> field(n, vector<char>(m));

    if (n*m % 4 != 0) {
        cout << "FAIL" << '\n';
        return 0;
    }

    if (m % 4 == 0) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j += 4) {
                char c = 'a' + (i + j/4) % 2;
                field[i][j] = field[i][j+1] = field[i][j+2] = field[i][j+3] = c;
            }
        }

    } else if (n % 4 == 0) {

        for (int i = 0; i < n; i += 4) {
            for (int j = 0; j < m; j++) {
                char c = 'a' + (i/4 + j) % 2;
                field[i][j] = field[i+1][j] = field[i+2][j] = field[i+3][j] = c;
            }
        }

    }
    else if (n % 2 == 0 && m % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < m; j += 2) {
                char c = 'a' + (i/2 + j/2) % 2;
                field[i][j] = field[i][j+1] = field[i+1][j] = field[i+1][j+1] = c;
            }
        }
    }
    else {
        cout << "FAIL" << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << field[i][j];
        }
        cout << '\n';
    }
    return 0;
}


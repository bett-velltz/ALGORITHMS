#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    pair<int, int> start;
    vector<vector<char>> v(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char el;
            cin >> el;
            if (el == '*' || el == 'S') {
                ++cnt;
            }
            if (el == 'S') {
                start = {i, j};
            }
            v[i].emplace_back(el);
        }
    }
    string answer;
    set<pair<int, int>> steps;

    for (int l = 0; l < cnt; ++l) {
        if (l == cnt-1) {
            if (start.first < n-1 && v[start.first+1][start.second] == 'S'
            && steps.find({start.first+1, start.second})==steps.end()) {
                ++start.first;
                answer += "D";
            } else if (start.first > 0 && v[start.first-1][start.second] == 'S'
            && steps.find({start.first-1, start.second})==steps.end()) {
                --start.first;
                answer += "U";
            } else if (start.second < m-1 && v[start.first][start.second+1] == 'S'
            && steps.find({start.first, start.second+1})==steps.end()) {
                ++start.second;
                answer += "R";
            } else if (start.second > 0 && v[start.first][start.second-1] == 'S'
            && steps.find({start.first, start.second-1})==steps.end()) {
                --start.second;
                answer += "L";
            }
            steps.insert({start.first, start.second});
            continue;
        }

        if (start.first < n-1 && v[start.first+1][start.second] == '*'
        && steps.find({start.first+1, start.second})==steps.end()) {
            ++start.first;
            answer += "D";
        } else if (start.first > 0 && v[start.first-1][start.second] == '*'
        && steps.find({start.first-1, start.second})==steps.end()) {
            --start.first;
            answer += "U";
        } else if (start.second < m-1 && v[start.first][start.second+1] == '*'
        && steps.find({start.first, start.second+1})==steps.end()) {
            ++start.second;
            answer += "R";
        } else if (start.second > 0 && v[start.first][start.second-1] == '*'
        && steps.find({start.first, start.second-1})==steps.end() ) {
            --start.second;
            answer += "L";
        }
        steps.insert({start.first, start.second});
    }
    cout << answer << '\n';
    return 0;
}
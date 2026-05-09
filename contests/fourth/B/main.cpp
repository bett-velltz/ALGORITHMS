#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main() {
    int m;
    cin >> m;

    map<string, int> mapp;
    vector<pair<string, string>> pairs;
    int ind = 0;

    for (int i = 0; i < m; ++i) {
        string one, two, str;
        cin >> one >> str >> two;
        if (mapp.find(one) == mapp.end()) mapp[one] = ind++;
        if (mapp.find(two) == mapp.end()) mapp[two] = ind++;
        pairs.emplace_back(one, two);
    }

    string f, s;
    cin >> s >> f;
    if (mapp.find(s) == mapp.end()) mapp[s] = ind++;
    if (mapp.find(f) == mapp.end()) mapp[f] = ind++;

    vector<vector<int>> reactions(mapp.size());
    for (int i = 0; i < pairs.size(); ++i) {
        reactions[mapp[pairs[i].first]].emplace_back(mapp[pairs[i].second]);
    }

    int start = mapp[s];
    int finish = mapp[f];

    vector<int> dist(mapp.size(), -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == finish) break;
        for (int u : reactions[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    cout << dist[finish] << '\n';

    return 0;
}
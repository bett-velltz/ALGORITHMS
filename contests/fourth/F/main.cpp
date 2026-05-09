#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<int> dist(10000, -1);
    vector<int> pred(10000, -1);
    queue<int> q;

    int start, finish;
    cin >> start >> finish;
    dist[start] = 0;
    q.push(start);


    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == finish) break;

        int a = v / 1000;
        int b = (v / 100) % 10;
        int c = (v / 10) % 10;
        int d = v % 10;

        if (a < 9) {
            int next1 = (a + 1) * 1000 + b * 100 + c * 10 + d;
            if (dist[next1] == -1) {
                dist[next1] = dist[v] + 1;
                q.push(next1);
                pred[next1] = v;
            }
        }

        if (d > 1) {
            int next2 = a * 1000 + b * 100 + c * 10 + (d - 1);
            if (dist[next2] == -1) {
                dist[next2] = dist[v] + 1;
                q.push(next2);
                pred[next2] = v;
            }
        }
        int next3 = d * 1000 + a * 100 + b * 10 + c;
        if (dist[next3] == -1) {
            dist[next3] = dist[v] + 1;
            q.push(next3);
            pred[next3] = v;
        }

        int next4 = b * 1000 + c * 100 + d * 10 + a;
        if (dist[next4] == -1) {
            dist[next4] = dist[v] + 1;
            q.push(next4);
            pred[next4] = v;
        }
    }
    vector<int> ans;

    for (int i = finish; i != -1; i = pred[i]) {
        ans.emplace_back(i);
    }

    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
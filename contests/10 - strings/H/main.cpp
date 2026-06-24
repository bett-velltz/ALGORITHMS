//
// Created by 1 on 23.06.2026.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    string s, j;
    cin >> s >> j;
    string str = s + '$' + j;
    int n = str.size();
    vector<int> z(n, 0);

    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {

        z[i] = max(0, min(r - i, z[i - l]));

        while (i + z[i] < n && str[i + z[i]] == str[z[i]]) {
            z[i]++;
        }

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }

    vector<int> p(j.size() + 1, -1);
    p[0] = 0;

    queue<int> q;
    q.push(0);

    int last = 0; // самая правая уже добавленная позиция

    while (!q.empty()) {
        int pos = q.front();

        /*рассматриваем позиции от 0 до размера строки Джека,
        позиции расположены между символами:

        | a b r a c a d a
        ^
                                          */
        q.pop();

        if (pos == j.size())
            break;

        int len = min(z[s.size() + 1 + pos], (int)s.size()); //максимальная длина префикса строки s, который совпадает с подстрокой j, начинающейся в позиции pos.
        int right = min((int)j.size(), pos + len); //указатель после конца повторяющего отрезка

        // добавляем только новые позиции
        int start = max(last + 1, pos + 1);

        for (int nxt = start; nxt <= right; nxt++) { //индексы позиций между симв в слове Джека
            p[nxt] = pos;
            q.push(nxt);
        }

        last = max(last, right);
    }

    if (p[j.size()] == -1) {
        cout << "Yes" << '\n';
        return 0;
    }
    cout << "No" << '\n';

    vector<string> ans;

    int cur = j.size();

    while (cur > 0) {
        int par = p[cur];
        ans.push_back(j.substr(par, cur - par));
        cur = par;
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}

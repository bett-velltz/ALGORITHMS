//C. Саратовская дилемма
//https://codeforces.com/group/NvH0Eve9m2/contest/695479/problem/C

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    int n, one_cnt, two_cnt;
    cin >> n >> one_cnt >> two_cnt;
    vector<int> yes;
    vector<int> no;
    vector<int> alone;
    vector<int> couples;
    string s;
    cin >> s;
    vector<int> v;
    for (char c:s) {
        v.emplace_back(c-'0');
    }

    for (int i = 1; i <= n; ++i) {
        int el = v[i-1];
        if (el == 0) {
            no.emplace_back(i);
        } else {
            yes.emplace_back(i);
        }
    }
    if (n > one_cnt + 2*two_cnt) {
        cout << "NO" << '\n';
        return 0;
    }

    if (one_cnt - (int)no.size() + 2*two_cnt < (int)yes.size()) {
        cout << "NO" << '\n';
        return 0;
    }

    //заполняю всех кто хочет один
    for (int i = 0; i < min(one_cnt, (int)no.size()); ++i) {
        alone.emplace_back(no[i]);
    }
    //если не хватило односпальных, кладу на двуспальные по одному
    int ext_alone = (int)no.size() - (int)alone.size();
    for (int i = 0; i < ext_alone; ++i) {
        couples.emplace_back(no[one_cnt + i]);
        couples.emplace_back(0);
    }

    //на остаток кроватей единичных кладу тех, кто готов вместе
    int readyalone = 0;

    for (int i = 0; i < min(one_cnt - (int)alone.size(), (int)yes.size()); ++i) {
        alone.emplace_back(yes[i]);
        ++readyalone;
    }
    //заполняю остаток нулями
    for (int i = (int)alone.size(); i < one_cnt; ++i) {
        alone.emplace_back(0);
    }
    //проверяю, что места ещё остались
    if (yes.size() - readyalone > two_cnt*2 - couples.size()) {
        cout << "NO" << '\n';
        return 0;
    }
    //всех ост готовых кладу вместе
    for (int i = readyalone; i < (int)yes.size(); ++i) {
        couples.emplace_back(yes[i]);
    }
    //заполняю остаток нулями
    int size = (int)couples.size();
    for (int i = size; i < two_cnt*2; ++i) {
        couples.emplace_back(0);
    }

    cout << "YES" << '\n';
    for (int i = 0; i < (int)alone.size(); ++i) {
        cout << alone[i] << '\n';
    }
    for (int i = 0; i < (int)couples.size(); i += 2) {
        cout << couples[i] << ' ' << couples[i+1] << '\n';
    }

    return 0;
}
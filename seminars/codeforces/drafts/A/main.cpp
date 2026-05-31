//C. Саратовская дилемма
//https://codeforces.com/group/NvH0Eve9m2/contest/695479/problem/C

#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n, one_cnt, two_cnt;
    cin >> n >> one_cnt >> two_cnt;
    vector<int> v(n);
    vector<int> yes;
    vector<int> no;
    vector<int> alone;
    vector<int> couples;


    for (int i = 1; i <= n; ++i) {
        int el;
        cin >> el;
        if (el == 0) {
            no.emplace_back(i);
        } else {
            yes.emplace_back(i);
        }
    }

    if (no.size() > one_cnt) {
        cout << "NO" << '\n';
        return 0;
    }
    //аполняю всех кто хочет один
    for (int i = 0; i < no.size(); ++i) {
        alone.emplace_back(no[i]);
    }
    //на остаток кроватей единичных кладу тех, кто готов вместе
    int readyalone = 0;

    for (int i = 0; i < min((one_cnt-alone.size()), yes.size()); ++i) {
        alone.emplace_back(yes[i]);
        ++readyalone;
    }
    //заполняю остаток нулями
    for (int i = 0; i < (one_cnt- alone.size()); ++i) {
        alone.emplace_back(0);
    }
    //всех ост готовых кладу вместе
    for (int i = readyalone; i < yes.size(); ++i) {
        couples.emplace_back(yes[i]);
    }
    //заполняю остаток нулями
    for (int i = 0; i < (two_cnt*2 - couples.size()); ++i) {
        couples.emplace_back(0);
    }

    cout << "YES" << '\n';
    for (int i = 0; i < alone.size(); ++i) {
        cout << alone[i] << '\n';
    }
    for (int i = 0; i < couples.size(); i += 2) {
        cout << couples[i] << ' ' << couples[i+1] << '\n';
    }
    return 0;
}
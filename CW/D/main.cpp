/*#include <iostream>
#include <vector>
using namespace std;

/*Алгоритм:
1. Для каждой буквы произведите заранее строим список ячеек, где она стоит.
2. Запускаем DFS из каждой ячейки с s[0].
3. На каждом этапе DFS проверяем соседей: если сосед содержит s[k+1]— рекурсивно идём туда.
4. Если дошли до конца слова — ответ YES.

int n, m;
vector<char> kir;
vector<vector<char>> field;


bool dfs(pair<int, int> c, int numb) {
    if (field[c.first][c.second] == '.') return false;
    if (numb == kir.size() - 1) {
        return true;
        //проверять && field[c.first][c.second] == kir[numb] не нужно, было проверено перед запуском dfs
    }

    //влево
    if (c.first > 0) {
        if (field[c.first - 1][c.second] == kir[numb + 1]) {
            if (dfs({c.first - 1, c.second}, numb + 1)) {
                return true;
            }
        }
    }
    //вправо
    if (c.first < n - 1) {
        if (field[c.first + 1][c.second] == kir[numb + 1]) {
            if (dfs({c.first + 1, c.second}, numb + 1)) {
                return true;
            }
        }
    }
    //вверх
    if (c.second > 0) {
        if (field[c.first][c.second - 1] == kir[numb + 1]) {
            if (dfs({c.first, c.second - 1}, numb + 1)) {
                return true;
            }
        }
    }
    //вниз
    if (c.second < m - 1) {
        if (field[c.first][c.second + 1] == kir[numb + 1]) {
            if (dfs({c.first, c.second + 1}, numb + 1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<pair<int, int>>> cells(26);

    cin >> n >> m;
    field.resize(n, vector<char> (m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int j = 0;
        for (auto simb: s) {
            field[i][j] = simb;
            if (simb != '.') {
                cells[simb - 'A'].emplace_back(i, j);
            }
            j++;
        }
    }
    string kirill;
    cin >> kirill;

    for (auto simb : kirill) {
        kir.emplace_back(simb);
    }

    for (auto cell : cells[kir[0]-'A']) {
        if (dfs(cell, 0)) {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
    return 0;
}*/

//рекурсия вызывает TL. Делаем итеративный способ

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*Алгоритм:
1. Для каждой буквы произведите заранее строим список ячеек, где она стоит.
2. Запускаем DFS из каждой ячейки с s[0].
3. На каждом этапе DFS проверяем соседей: если сосед содержит s[k+1]— рекурсивно идём туда.
4. Если дошли до конца слова — ответ YES.*/

int n, m;
vector<char> kir;
vector<vector<char>> field;

int main() {
    vector<vector<pair<int, int>>> cells(26);

    cin >> n >> m;
    field.resize(n, vector<char> (m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int j = 0;
        for (auto simb: s) {
            field[i][j] = simb;
            if (simb != '.') {
                cells[simb - 'A'].emplace_back(i, j);
            }
            j++;
        }
    }
    string kirill;
    cin >> kirill;

    for (auto simb : kirill) {
        kir.emplace_back(simb);
    }

    // стек хранит {строка, столбец, глубина}
    stack<tuple<int,int,int>> st;

    for (auto [r, c] : cells[kir[0]-'A']) {
        st.push({r, c, 0});
    }
    //Кладём все стартовые клетки (с первой буквой слова) в стеке с глубиной 0.
    while (!st.empty()) {
        auto [r, c, depth] = st.top();
        st.pop();

        if (depth == (int)kir.size() - 1) {
            cout << "YES\n";
            return 0;
        }
        //Если глубина равна индексу последней цифры — слово найдено.

        char need = kir[depth + 1];
        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int ni = r + di[d];
            int nj = c + dj[d];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && field[ni][nj] == need) {
                st.push({ni, nj, depth + 1});
            }
        }
    }
    cout << "NO\n";
    //Стек опустел, путь не найден.
    return 0;
}
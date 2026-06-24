//
// Created by 1 on 23.06.2026.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int k = 26;

struct Vertex {
    Vertex* to[k] = {0}; //массив указателей на детей
    bool terminal = 0;
};

Vertex *root = new Vertex();

void add_string(string &s) {
    Vertex* v = root;
    for (char c : s) {
        int idx = c - 'a'; // получаем число от 0 до 25
        if (!v->to[idx])
            v->to[idx] = new Vertex();
        v = v->to[idx];
    }
    v->terminal = true;
}

int dfs(Vertex* v) {
    int res = 0;

    for (int i = 0; i < 26; i++) {
        if (v->to[i]) {
            res = max(res, dfs(v->to[i]));
        }
    }
    if (v->terminal) {
        res += 1;
    }

    return res;
}

int main() {
    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        add_string(s);
    }

    cout << dfs(root);
    return 0;
}
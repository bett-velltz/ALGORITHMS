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
    bool terminal = false;
    int cnt = 0;
};

Vertex *root = new Vertex();

void add_string(string &s) {
    Vertex* v = root;
    for (char c : s) {
        int idx = c - 'a'; // получаем число от 0 до 25
        if (!v->to[idx]) {
            v->to[idx] = new Vertex();
        }
        v = v->to[idx];
        v->cnt++;
    }
    v->terminal = true;
}

string function(int el) {
    Vertex* v = root;
    string res;
    while (true) {
        if (v->terminal) {
            if (el == 1) {
                return res;
            }
            el--;
        }
        for (int i = 0; i < k; i++) {
            if (!v->to[i]) continue;
            if (v->to[i]->cnt >= el) {
                res += (char)('a' + i);
                v = v->to[i];
                break;
            }
            el -= v->to[i]->cnt;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (isdigit(s[0])) {
            cout << function(stoi(s)) << '\n';
        } else {
            add_string(s);
        }
    }
    return 0;
}
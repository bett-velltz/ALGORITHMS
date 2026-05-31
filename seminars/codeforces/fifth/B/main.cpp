#include <iostream>
#include <vector>

using namespace std;
//динамическое программирование

int main() {
    vector<char> word;
    string s;
    cin >> s;

    for (auto ch : s) {
        word.emplace_back(ch);
    }

    long long w = 0;
    long long wo = 0;
    long long wow = 0;

    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == 'o') {
            wo += w;
        } else {
            if (i != 0 && word[i-1] == 'v') {
                ++w;
                wow += wo;
            }
        }
    }
    cout << wow << '\n';
    return 0;
}

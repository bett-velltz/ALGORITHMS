#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> vect;

vector<int> tree_center(vector<vector<int>>& adj, int n) {
//крайние случаи
    if (n == 1) return {0};
    if (n == 2) return {0, 1};

    vector<int> degree(n);
    for (int v = 0; v < n; v++)
        degree[v] = adj[v].size();

//degree[v]— количество соседей вершин v. Это число будет уменьшаться по мере удаления листьев, имитируя «сжатие» дерева. Сам список adj мы не трогаем.

    queue<int> leaves;
    for (int v = 0; v < n; v++)
        if (degree[v] == 1)
            leaves.push(v);
    //это был первый слой листьев

    int remaining = n;
    //счётчик оставшихся вершин. Как только их станет ≤ 2 — мы дошли до центра и остановились:

    //ветка цикла - стирание слоя
    while (remaining > 2) {
        int layer_size = leaves.size();
        //размер текущего слоя
        remaining -= layer_size;
        //сразу вычитаем - удаляем весь слой одновременно

        for (int i = 0; i < layer_size; i++) {
            int leaf = leaves.front();
            leaves.pop();
            //удаляем из очереди кол-во листьев, точно равное размеру слоя
            for (int neighbor : adj[leaf]) {
                degree[neighbor]--;
                if (degree[neighbor] == 1)
                    leaves.push(neighbor);
            }
            //обновили соседей
        }
    }

    vector<int> center;
    while (!leaves.empty()) {
        center.push_back(leaves.front());
        leaves.pop();
    }
    return center;
    //После выхода из цикла в очереди остается ровно 1 или 2 вершины — это и есть центр. Просто перекладываем их в вектор и возвращаем.
}


int main() {
    int N;
    cin >> N;
    vect.resize(N);
    for (int i = 1; i < N; ++i) {
        int a;
        cin >> a;
        --a;
        vect[i].push_back(a);
        vect[a].push_back(i);
    }
    vector<int> ans = tree_center(vect, N);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i]+1 << ' ';
    }
    cout << '\n';
    return 0;
}
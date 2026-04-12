#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DistFinder {
    vector<vector<int>> g;
    vector<int> dist;
public:
    DistFinder(const vector<vector<int>>& g_) : g(g_), dist(g_.size(), -1) {}

    void dfs(int point, int cur_dist) {
        dist[point] = cur_dist;
        for (int next : g[point]) {
            if (dist[next] == -1) {
                dfs(next, cur_dist + 1);
            }
        }
    }
    friend int get_max_distance(vector<vector<int>>, int, int);
};
int get_max_distance(vector<vector<int>> g, int ch, int fox) {
    DistFinder chicken_dist(g);
    DistFinder fox_dist(g);
    chicken_dist.dfs(ch, 0);
    fox_dist.dfs(fox, 0);
    int r = 0;
    for (int i = 0; i < g.size(); ++i) {
        if (chicken_dist.dist[i] < fox_dist.dist[i]) {
            r = max(r, fox_dist.dist[i]);
        }
    }
    return r;
}
int main() {
    vector<vector<int>> g = {
            {1},
            {0, 2},
            {1, 3},
            {2, 4},
            {3}
    };
    int fox = 0, ch = 4;
    cout << get_max_distance(g, ch, fox);
    return 0;
}
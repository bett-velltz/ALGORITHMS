//МОСТЫ

void dfs(int v, int p=-1) {
    used[v] = true;
    ++timer;

    tin[v] = tout[v] = timer;
    for (const auto to : gr[v]) {
        if (!used[to]) {
            dfs(to, v);
            tout [v] = std::min(tout[v], tout[to]);
            if (tin[v] < tout[to]) {
                int x = std::min(v, to);
                int y = std::max(v, to);
                ans.push_back(dict[{x, y}]);
                ++ans_cnt;
            }
        } else if(to != p) {
            tout [v] = std::min(tout[v], tin[to]);
        }
    }
}
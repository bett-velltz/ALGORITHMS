void dfs(int pos, std::vector<std::vector<int>>& graf, std::vector<std::vector<int>>& tout, int& timer, int pred = -1) {
    used[pos] = true;
    ++timer;
    int cnt = 0;
    tin[pos] = tout[pos] = timer;
    for (const auto to : graf[pos]) {
        if (to == pred) {
            continue;
        }
        if (!used[to]) {
            dfs(to, graf, used, tin, tout, timer, pos);
            ++cnt;
            tout[pos] = std::min(tout[pos], tout[to]);

            if ((pred != -1) && (tout[to] >= tin[pos])) {
                ans.insert(pos);
            }
        } else {
            tout[pos] = std::min(tout[pos], tin[to]);
        }
    }
    if ((pred == -1) && (cnt >= 2)) {
        ans.insert(pos);
    }
}
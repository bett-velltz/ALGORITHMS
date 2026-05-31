#include <iostream>
#include <vector>
#include <queue>
int main() {
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<int> c(n+1);
    for (int i=1;i<=n;++i) {
        std::cin >> c[i];
    }
    std::vector<std::vector<int> > ma(n+1);
    for (int i=1;i<=m;++i) {
        int x;
        int y;
        std::cin >> x >> y;
        ma[x].push_back(y);
        ma[y].push_back(x);
    }
    std::vector<int> v(n+1,0);
    int ans=0;
    for (int i=1;i<=n;++i) {
        if (!v[i]) {
            long long mc=c[i];
            std::queue<int> q;
            q.push(i);
            v[i]=1;
            while (!q.empty()) {
                int v=q.front();
                q.pop();
                mc=std::min(mc,(long long)c[v]);
                for (auto& u:ma[v]) {
                    if (!v[u]) {
                        v[u]=1;
                        q.push(u);
                    }
                }
            }
            ans+=mc;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
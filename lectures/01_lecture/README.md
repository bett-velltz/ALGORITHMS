Реализация невзвешенного графа:

    int n, m;
    cin >> n >> m;
    vector<vector<int>> gr1(n);
    vector<vector<int>> gr2(n, vector<int> (n, 0));
    
    for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    gr1[a].push_back(b);
    gr1[b].push_back(a);
    
    gr2[a][b] = 1;
    gr2[b][a] = 1;
    }

Реализация взвешенного графа:
    
    struct edge {
    int to;
    int w;
    };
    —-----------------
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> gr(n);
    for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    gr[a].push_back({b, w});
    gr[b].push_back({a, w});
    }

struct SCComponents {
    int n;
    Graph G, rG;
    vector<int> order, vis, cmp;
    SCComponents(int n) : n(n), vis(n), cmp(n, -1) {
        G.resize(n, true);
        rG.resize(n, true);
    }
    void add_edge(int u, int v) {
        G.add_edge(u, v);
        rG.add_edge(v, u);
    }
    void dfs(int i) {
        if(vis[i]) return;
        vis[i] = 1;
        for(auto e : G[i]) dfs(e.to);
        order.push_back(i);
    }
    void rdfs(int i, int k) {
        if(cmp[i] != -1) return;
        cmp[i] = k;
        for(auto e : rG[i]) rdfs(e.to, k);
    }
    void build() {
        for(int i = 0; i < n; i++) dfs(i);
        reverse(order.begin(), order.end());
        int idx = 0;
        for(auto i : order) 
            if(cmp[i] == -1) rdfs(i, idx++);
    }
};
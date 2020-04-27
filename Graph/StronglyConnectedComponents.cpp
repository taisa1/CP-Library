//@docs Docs/StronglyConnectedComponents.md
struct SCC {
    int n;
    vector<int> ord, vis, cm;
    vector<vector<int>> bl, G, rG;
    SCC(int n) : n(n), bl(n), G(n), rG(n), cm(n), vis(n) {}
    void addedge(int u, int v) {
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    void dfs(int i) {
        vis[i] = 1;
        for (auto &e : G[i]) {
            if (vis[e]) continue;
            dfs(e);
        }
        ord.eb(i);
    }
    void rdfs(int i, int c) {
        vis[i] = 1;
        bl[c].emplace_back(i);
        cm[i] = c;
        for (auto &e : rG[i]) {
            if (vis[e]) continue;
            rdfs(e, c);
        }
    }
    //強連結成分分解し、成分数を返す bl[i]:i番目の成分に属する頂点集合、cm[i]:頂点iの成分
    //成分はトポロジカル順に並ぶ
    int scc() {
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i);
        }
        reverse(ord.begin(), ord.end());
        vis.assign(n, 0);
        int k = 0;
        for (auto &e : ord) {
            if (!vis[e]) {
                bl.emplace_back(vector<int>());
                rdfs(e, k);
                k++;
            }
        }
        return k;
    }
};
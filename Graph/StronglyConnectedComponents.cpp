vector<vector<int>> G;
struct SCC {
    int n;
    vector<int> ord, vis, cm;
    vector<vector<int>> bl, rG;
    SCC(int n) : n(n), bl(n), rG(n), cm(n) {}
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
        bl[c].eb(i);
        cm[i] = c;
        for (auto &e : rG[i]) {
            if (vis[e]) continue;
            rdfs(e, c);
        }
    }
    void build() {
        for (int i = 0; i < n; i++) {
            for (auto &e : G[i]) {
                rG[e].eb(i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i);
        }
        reverse(all(ord));
        vis.assign(n, 0);
        int k = 0;
        for (auto &e : ord) {
            if (!vis[e]) {
                bl.eb(vector<int>());
                rdfs(e, k);
                k++;
            }
        }
    }
};
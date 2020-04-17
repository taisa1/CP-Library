vector<vector<int>> G;
struct LCA {
    vector<vector<int>> par;
    vector<int> dep;
    int n;
    void dfs(int i, int p) {
        par[0][i] = p;
        for (auto &e : G[i]) {
            dep[e] = dep[i] + 1;
            dfs(e);
        }
    }
    void build(int n_, int rt = 0) {
        n = n_;
        dep.resize(n);
        par.resize(30, vector<int>(n, -1));
        dfs(rt, -1);
        for (int i = 1; i < 30; i++) {
            for (int j = 0; j < n; j++) {
                if (par[i - 1][j] != -1) {
                    par[i][j] = par[i - 1][par[i - 1][j]];
                }
            }
        }
    }
    int get(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = 19; i >= 0; i--) {
            if (((dep[v] - dep[u]) >> i) & 1) v = par[i][v];
        }
        if (u == v) return u;
        for (int i = 19; i >= 0; i--) {
            if (par[i][u] != par[i][v]) {
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    }
};
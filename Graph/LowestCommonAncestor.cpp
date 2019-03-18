vector<vector<int>> G, par;
vector<int> dep;
int n;
void dfs(int i, int p) {
    for(auto e : G[i]) {
        if(e == p) continue;
        par[e][0] = i;
        dep[e] = dep[i] + 1;
        dfs(e, i);
    }
}
void build() {
    par[0][0] = -1;
    dep[0] = 0;
    dfs(0, -1);
    for(int j = 1; j < 20; j++) {
        for(int i = 0; i < n; i++) {
            if(par[i][j - 1] == -1) {
                par[i][j] = -1;
            } else {
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
    }
}
int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 19; i >= 0; i--) {
        if(((dep[v] - dep[u]) >> i) & 1) v = par[v][i];
    }
    if(u == v) return u;
    for(int i = 19; i >= 0; i--) {
        if(par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
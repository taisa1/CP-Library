struct CentroidD {
    vector<vector<int>> G, be;
    vector<int> sz, vis;
    CentroidD(int n) : G(n), be(n), sz(n), vis(n) {}
    void addedge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void szd(int i, int p) {
        sz[i] = 1;
        for (auto &e : G[i]) {
            if (e == p || vis[e]) continue;
            szd(e, i);
            sz[i] += sz[e];
        }
    }
    int findc(int i, int p, int lim) {
        for (auto &e : G[i]) {
            if (e == p || vis[e]) continue;
            if (sz[e] > lim) {
                return findc(e, i, lim);
            }
        }
        return i;
    }
    void bel(int i, int p, int c) {
        be[i].eb(c);
        for (auto &e : G[i]) {
            if (e == p || vis[e]) continue;
            bel(e, i, c);
        }
    }
    void build(int rt) {
        szd(rt, -1);
        int c = findc(rt, -1, sz[rt] / 2);
        bel(rt, -1, c);
        vis[c] = 1;
        for (auto &e : G[c]) {
            if (vis[e]) continue;
            build(e);
        }
        vis[c] = 0;
    }
    void calc(int rt) {
        szd(rt, -1);
        int c = findc(rt, -1, sz[rt] / 2);
        //ここで部分木について処理
        vis[c] = 1;
        for (auto &e : G[c]) {
            if (vis[e]) continue;
            calc(e);
        }
    }
};
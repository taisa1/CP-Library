struct UnionFind {
    vector<int> par, sz;
    UnionFind(int n) : par(n) {
        sz.resize(n, 1);
        iota(par.begin(), par.end(), 0);
    }
    inline int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
    inline bool same(int u, int v) {
        return find(u) == find(v);
    }
};

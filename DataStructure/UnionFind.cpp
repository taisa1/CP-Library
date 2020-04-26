//@docs Docs/UnionFind.md
struct UnionFind {
    vector<int> par, sz;
    UnionFind(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    inline int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
    inline int size(int x) {
        return sz[find(x)];
    }
    inline bool same(int u, int v) {
        return find(u) == find(v);
    }
};

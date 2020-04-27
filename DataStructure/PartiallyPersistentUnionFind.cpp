//@docs Docs/PartiallyPersistentUnionFind.md
struct UnionFind {
    vector<int> par, sz, tim;
    UnionFind(int n) : par(n), sz(n, 1), tim(n, -1) {
        iota(par.begin(), par.end(), 0);
    }
    //時刻tのuniteの後のrootを求める
    inline int find(int x, int t) {
        while (par[x] != x && tim[x] <= t) x = par[x];
        return x;
    }
    //与えられるtは広義単調増加
    bool unite(int u, int v, int t) {
        u = find(u, t), v = find(v, t);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        tim[v] = t;
        sz[u] += sz[v];
        return true;
    }
    inline bool same(int u, int v, int t) {
        return find(u, t) == find(v, t);
    }
};
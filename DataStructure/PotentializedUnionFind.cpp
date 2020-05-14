//@docs Docs/PotentializedUnionFind.cpp
template <class T>
struct UnionFind {
    vector<int> par, sz;
    vector<T> val;
    UnionFind(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
        val.resize(n);
    }
    inline int find(int x) {
        if (x == par[x]) return x;
        int root = find(par[x]);
        val[x] += val[par[x]];
        return par[x] = root;
    }
    inline T value(int x) { //W(x)-W(root)
        find(x);
        return val[x];
    }
    bool unite(int u, int v, T w) { //W(v)=W(u)+w
        w += value(u), w -= value(v);
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v), w *= -1;
        sz[u] += sz[v];
        par[v] = u;
        val[v] = w;
        return true;
    }
    inline int size(int x) {
        return sz[find(x)];
    }
    inline bool same(int u, int v) {
        return find(u) == find(v);
    }
};

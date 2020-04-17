struct UnionFind {
    int t;
    vector<int> par, siz, tim;
    UnionFind(int n) : par(n), tim(n, INF) {
        siz.assign(n, INF);
        iota(par.begin(), par.end(), 0);
        t = -1;
    }
    int find(int x, int ti) {
        while (x != par[x] && ti >= tim[par[x]]) {
            x = par[x];
        }
        return x;
    }
    bool unite(int u, int v) {
        u = find(u, t), v = find(v, t);
        t++;
        if (u == v) return false;
        if (siz[u] < siz[v]) swap(u, v);
        par[v] = u;
        siz[u] += siz[v];
        tim[v] = t;
        return true;
    }
    //ti回目(0-indexed)のunite後の状態を調べる
    bool same(int u, int v, int ti) { return find(u, ti) == find(v, ti); }
};
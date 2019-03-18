struct UnionFind {
    int t;
    vector<int> par, siz, tim;
    UnionFind(int n) {
        par.resize(n);
        siz.resize(n, 1);
        tim.resize(n, INF);
        for(int i = 0; i < n; i++) par[i] = i;
    }
    int find(int x, int ti) {
        while(x != par[x] && ti >= tim[par[x]]) {
            x = par[x];
        }
        return x;
    }
    bool unite(int u, int v) {
        u = find(u, t), v = find(v, t);
        if(u == v) return false;
        t++;
        if(siz[u] < siz[v]) swap(u, v);
        par[v] = u;
        siz[u] += siz[v];
        tim[v] = t;
        return true;
    }
    bool same(int u, int v, int ti) { return find(u, ti) == find(v, ti); }
};
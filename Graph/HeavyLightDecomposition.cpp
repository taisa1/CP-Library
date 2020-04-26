//@docs Docs/HeavyLightDecomposition.md
struct HLD {
    int n;
    vector<vector<int>> G;
    vector<int> sz, rt, id, par, out;
    int pos, cnt;
    HLD(int n) : n(n), G(n), sz(n, 1), rt(n, -1), id(n), par(n, -1), out(n), cnt(0) {}
    void addedge(const int &u, const int &v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        cnt++;
        if (cnt == n - 1) {
            build();
        }
    }
    void build() {
        szdfs(0, -1);
        id[0] = 0;
        rt[0] = 0;
        pos = 0;
        hld(0, -1);
    }
    void szdfs(int i, int p) {
        for (auto &e : G[i]) {
            if (e == p) continue;
            szdfs(e, i);
            par[e] = i;
            sz[i] += sz[e];
            if (sz[e] > sz[G[i][0]]) {
                swap(G[i][0], e);
            }
        }
    }
    void hld(int i, int p) {
        id[i] = pos;
        pos++;
        for (auto &e : G[i]) {
            if (e == p) continue;
            if (e == G[i][0]) {
                rt[e] = rt[i];
            } else {
                rt[e] = e;
            }
            hld(e, i);
        }
        out[i] = pos;
    }
    template <class F>
    void getpath(int u, int v, const F &f) { //f:[a,b)
        while (1) {
            if (id[u] > id[v]) swap(u, v);
            if (rt[u] == rt[v]) {
                f(id[u], id[v] + 1);
                break;
            } else {
                f(id[rt[v]], id[v] + 1);
                v = par[rt[v]];
            }
        }
    }
    template <class F>
    void getsubtree(const int &u, const F &f) { //f:[a,b)
        f(id[u], out[u]);
    }
    inline int index(const int &i) {
        return id[i];
    }
};
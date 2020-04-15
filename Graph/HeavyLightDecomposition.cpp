//Path Sum and Subtree Sum
struct HLD {
    int n;
    vector<vector<int>> G;
    vector<int> sz, rt, id, par, out;
    int pos;
    HLD(int n) : n(n), G(n), sz(n, 1), rt(n, -1), id(n), par(n, -1), out(n) {}
    void addedge(int u, int v) {
        G[u].eb(v);
        G[v].eb(u);
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
    inline ll f(int a, int b) { return 0; } //[a,b]
    ll get_v(int u, int v) {
        ll res = 0;
        while (1) {
            if (id[u] > id[v]) swap(u, v);
            if (rt[u] == rt[v]) {
                res += f(id[u], id[v]);
                break;
            } else {
                res += f(id[rt[v]], id[v]);
                v = par[rt[v]];
            }
        }
        return res;
    }
    ll subtree(int u) {
        return f(id[u], out[u]);
    }
};
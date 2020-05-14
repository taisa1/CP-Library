//@docs Docs/QuickFind.md
struct QuickFind {
    int n;
    vector<vector<int>> vs;
    vector<int> root;
    QuickFind(int n) : n(n), vs(n), root(n) {
        iota(root.begin(), root.end(), 0);
        for (int i = 0; i < n; i++) {
            vs[i].emplace_back(i);
        }
    }
    inline int size(int u) {
        return vs[root[u]].size();
    }
    bool unite(int u, int v) {
        u = root[u], v = root[v];
        if (u == v) return false;
        if (size(u) < size(v)) swap(u, v);
        for (auto &e : vs[v]) {
            vs[u].emplace_back(e);
            root[e] = u;
        }
        return true;
    }
    inline int same(int u, int v) {
        return root[u] == root[v];
    }
    vector<int> &elements(int u) {
        return vs[root[u]];
    }
};
template <class T>
struct FordFulkerson {
    struct edge {
        int to;
        int rev;
        T cap;
    };
    vector<vector<edge>> G;
    vector<int> vis;
    FordFulkerson(int n) : G(n), vis(n) {}
    inline void addedge(int u, int v, T c) {
        G[u].emplace_back(edge{v, (int)G[v].size(), c});
        G[v].emplace_back(edge{u, (int)G[u].size() - 1, 0});
    }
    T dfs(int i, const int t, T flow) {
        if (i == t) return flow;
        vis[i] = 1;
        for (auto &e : G[i]) {
            if (e.cap == 0 || vis[e.to]) continue;
            T x = dfs(e.to, t, min(flow, e.cap));
            if (x > 0) {
                e.cap -= x;
                G[e.to][e.rev].cap += x;
                return x;
            }
        }
        return 0;
    }
    T maxflow(int s, int t) {
        T res = 0;
        while (1) {
            fill(all(vis), 0);
            T inc = dfs(s, t, INF);
            if (inc > 0) {
                res += inc;
            } else {
                break;
            }
        }
        return res;
    }
};
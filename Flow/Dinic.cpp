
template <class T>
struct Dinic {
    struct edge {
        int to, rev;
        T cap;
        edge(int to, int rev, T cap) : to(to), rev(rev), cap(cap) {}
    };
    int n;
    vector<vector<edge>> G;
    vector<int> lev, itr;
    Dinic(int n) : n(n), G(n), lev(n), itr(n) {}
    void add_edge(int u, int v, T cap) {
        G[u].emplace_back(v, G[v].size(), cap);
        G[v].emplace_back(u, (int)G[u].size() - 1, 0);
    }
    void bfs(int s) {
        lev.assign(n, -1);
        queue<int> q;
        lev[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto &e : G[i]) {
                if (lev[e.to] == -1 && e.cap > 0) {
                    lev[e.to] = lev[i] + 1;
                    q.push(e.to);
                }
            }
        }
    }
    T dfs(int i, const int &t, T flow) {
        if (i == t) return flow;
        for (; itr[i] < G[i].size(); itr[i]++) {
            edge &e = G[i][itr[i]];
            if (e.cap == 0 || lev[e.to] <= lev[i]) continue;
            int x = dfs(e.to, t, min(flow, e.cap));
            if (x > 0) {
                e.cap -= x;
                G[e.to][e.rev].cap += x;
                return x;
            }
        }
        return 0;
    }
    T maxflow(const int &s, const int &t) {
        T res = 0, inc;
        while (1) {
            bfs(s);
            if (lev[t] == -1) break;
            itr.assign(n, 0);
            while (1) {
                inc = dfs(s, t, INF);
                if (inc == 0) break;
                res += inc;
            }
        }
        return res;
    }
};
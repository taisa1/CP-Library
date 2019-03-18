struct edge {
    int to;
    ll cap;
    int rev;
};
vector<edge> G[100010];
int lev[100010];
int itr[100010];
struct Dinic {
    void add_edge(int from, int to, ll cap) {
        G[from].push_back((edge){to, cap, (int)G[to].size()});
        G[to].push_back((edge){from, 0LL, (int)G[from].size() - 1});
    }

    void bfs(int s) {
        memset(lev, -1, sizeof(lev));
        queue<int> q;
        lev[s] = 0;
        q.push(s);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int i = 0; i < G[v].size(); i++) {
                edge &e = G[v][i];
                if(e.cap > 0 && lev[e.to] < 0) {
                    lev[e.to] = lev[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    ll dfs(int v, int t, ll f) {
        if(v == t) return f;
        for(int &i = itr[v]; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if(e.cap > 0 && lev[v] < lev[e.to]) {
                ll d = dfs(e.to, t, min(f, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll max_flow(int s, int t) {
        ll flow = 0;
        for(;;) {
            bfs(s);
            if(lev[t] < 0) return flow;
            memset(itr, 0, sizeof(itr));
            ll f;
            while((f = dfs(s, t, LINF)) > 0) {
                flow += f;
            }
        }
    }
};
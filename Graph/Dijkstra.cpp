struct Dijkstra {
    int n;
    vector<vector<P>> G;
    Dijkstra(int n) : n(n), G(n) {}
    void addedge(int u, int v, ll c) { G[u].emplace_back(v, c); }
    vector<ll> dijkstra(int st) {
        priority_queue<P, vector<P>, greater<P>> q;
        vector<ll> d(n, INF);
        d[st] = 0;
        q.emplace(0, st);
        while (!q.empty()) {
            int v = q.top().second;
            q.pop();
            for (auto &e : G[v]) {
                if (d[e.first] > d[v] + e.second) {
                    d[e.first] = d[v] + e.second;
                    q.emplace(d[e.first], e.first);
                }
            }
        }
        return d;
    }
};
int n;
vector<vector<P>> G;
vector<ll> dijkstra(int st) {
    priority_queue<P, vector<P>, greater<P>> q;
    vector<ll> d(n, INF);
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
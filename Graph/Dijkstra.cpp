vector<ll> dijkstra(int s, Graph G) {
    int n = G.siz;
    assert(0 <= s && s < n);
    vector<ll> d(n, LINF);
    priority_queue<P, vector<P>, greater<P>> q;
    d[s] = 0;
    q.push(P(0, s));
    while(!q.empty()) {
        int v = q.top().second;
        q.pop();
        for(auto e : G[v]) {
            if(d[e.to] <= d[v] + e.cost) continue;
            d[e.to] = d[v] + e.cost;
            q.push(P(d[e.to], e.to));
        }
    }
    return d;
}
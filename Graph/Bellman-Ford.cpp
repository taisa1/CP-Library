struct edge {
    int from, to, cost;
};
vector<int> bellman_ford(vector<edge> g, int V, int s) {
    vector<int> d(V, INF);
    d[s] = 0;
    for(int i = 0; i < V - 1; i++) {
        for(int j = 0; j < g.size(); j++) {
            edge e = g[j];
            if(d[e.from] == INF) continue;
            d[e.to] = min(d[e.to], d[e.from] + e.cost);
        }
    }
    for(int i = 0; i < g.size(); i++) {
        edge e = g[i];
        if(d[e.from] == INF) continue;
        if(d[e.from] + e.cost < d[e.to]) return vector<int>();
    }
    return dist;
}
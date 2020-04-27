//@docs Docs/Dijkstra.md
template <class T>
struct Dijkstra {
    int n;
    vector<vector<pair<T, int>>> G;
    Dijkstra(int n) : n(n), G(n) {}
    void addedge(const int &u, const int &v, const T &c) { G[u].emplace_back(v, c); }
    vector<T> dijkstra(const int &st) {
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
        vector<T> d(n, INF);
        d[st] = 0;
        q.emplace(0, st);
        while (!q.empty()) {
            int v = q.top().second;
            T dd = q.top().first;
            q.pop();
            if (d[v] < dd) continue;
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
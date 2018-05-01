struct edge{int to,cost;};
vector<int> dijkstra(int s,vector<edge> g[]){
    vector<int> d(MAX,INF);
    priority_queue<P,vector<P>,greater<P>> q;
    d[s]=0;
    q.push(P(0,s));
    while(!q.empty()){
        P p=q.top();q.pop();
        int v=p.second;
        for(int i=0;i<g[v].size();i++){
            edge e=g[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                q.push(P(d[e.to],e.to));
            }
        }
    }
    return d;
}
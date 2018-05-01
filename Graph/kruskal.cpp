struct edge{int from,to,cost;};
bool comp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}
int kruskal(vector<edge> g,int V,int E){
    Unionfind uf(V);
    sort(all(g),comp);
    int res=0;
    for(int i=0;i<E;i++){
        edge e=g[i];
        if(!uf.same(e.from,e.to)){
            uf.unite(e.from,e.to);
            res+=e.cost;
        }
    }
    return res;
}
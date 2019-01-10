struct Graph{
    struct edge{int to;ll cost;};
    int siz;
    bool dir;
    vector<vector<edge>> G;
    Graph(){}
    Graph(int siz,bool dir):siz(siz),dir(dir){
        G.resize(siz+1);
    }
    void resize(int nsiz,bool ndir){
        dir=ndir;
        siz=nsiz;
        G.resize(siz+1);
    }
    void add_edge(int u,int v){
        assert(0<=u&&u<siz);assert(0<=v&&v<siz);
        G[u].push_back({v,0});
        if(!dir)G[v].push_back({u,0});
    }
    void add_edge(int u,int v,ll cost){
        assert(0<=u&&u<siz);assert(0<=v&&v<siz);
        G[u].push_back({v,cost});
        if(!dir)G[v].push_back({u,cost});
    }
    vector<edge>& operator[](const int& idx){
        assert(0<=idx&&idx<siz);
        return G[idx];
    } 
};
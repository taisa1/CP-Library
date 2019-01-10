struct Tree{
    int siz;
    vector<vector<int>> to;
    vector<int> par;
    Graph(int siz):siz(siz){
        to.resize(siz);
        par.resize(siz);
    }
    void add_edge(int u,int v){//1-indexed->0-indexed
        --u;--v;
        assert(0<=u&&u<siz);assert(0<=v&&v<siz);
        to[u].push_back(v);
        par[v]=u;//rooted
    }
    vector<edge>& operator[](const int& idx){
        assert(0<=idx&&idx<siz);
        return to[idx];
    }
};
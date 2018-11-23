struct HLDecomposition{
    int n,pos;
    vector<vector<int>> G;
	//新index,heavy-edgeの最初の要素のindex,部分木のサイズ,heavy-edgeでの次の頂点,親,深さ,元index
    vector<int> nid,fst,siz,hv,par,dep,id;
	Segtree tree;
    HLDecomposition(int n_){
        n=n_,pos=0;
        G.resize(n);
        nid.resize(n,-1);
        fst.resize(n);
        siz.resize(n,1);
        hv.resize(n,-1);
        par.resize(n);
        dep.resize(n);
        id.resize(n);
    }
    void add_edge(int u,int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void build(int rt){//rtを根とする木についてHL分解
		par[rt]=-1;
		dep[rt]=0;
        dfs(rt);
        bfs(rt);
    }
    void dfs(int v){//heavy-edgeを選んでいく
        int res=0;
        for(auto u:G[v]){
            if(u==par[v])continue;
            par[u]=v;
            dep[u]=dep[v]+1;
            dfs(u);
            siz[v]+=siz[u];
            if(res<siz[u]){
                res=siz[u];
                hv[v]=u;
            }
        }
    }
    void bfs(int r){//BFSで情報を保存する
        queue<int> q;
        q.push(r);
        while(!q.empty()){
            int h=q.front();q.pop();
            for(int i=h;i!=-1;i=hv[i]){
                nid[i]=pos++;
                id[nid[i]]=i;
                fst[i]=h;
                for(int j:G[i]){
                    if(j!=par[i]&&j!=hv[i])q.push(j);
                }
            }
        }
    }
    int lca(int u,int v){
        while(1){
            if(nid[u]>nid[v])swap(u,v);
            if(fst[u]==fst[v])return u;
            v=par[fst[v]];
        }
    }
};
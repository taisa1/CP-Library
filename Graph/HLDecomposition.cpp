struct HLDecomposition{
    int n,pos;
    vector<vector<int>> G;
    vector<int> nid,fst,siz,hv,par,dep,id;
    HLDecomposition(int n_):n(n_),pos(0),G(n),nid(n,-1),fst(n),siz(n,1),hv(n,-1),par(n),dep(n),id(n){}
    void add_edge(int u,int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void build(int rt){
        par[rt]=-1;
        dep[rt]=0;
        dfs(rt);
        bfs(rt);
    }
    void dfs(int v){
        int ma=0;
        for(auto u:G[v]){
            if(u==par[v])continue;
            par[u]=v;
            dep[u]=dep[v]+1;
            dfs(u);
            siz[v]+=siz[u];
            if(ma<siz[u]){
                ma=siz[u];
                hv[v]=u;
            }
        }
    }
    void bfs(int rt){
        queue<int> q;
        q.push(rt);
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
    void query(int u,int v){//[u,v]
        while(1){
            if(nid[u]>nid[v])swap(u,v);
            //[max(nid[fst[v]],nid[u]),nid[v]];
            cout<<max(nid[fst[v]],nid[u])<<" "<<nid[v]<<endl;
            if(fst[u]!=fst[v]){
                v=par[fst[v]];
            }else{
                break;
            }
        }
    }
    void query_edge(int u,int v){
        while(1){
            if(nid[u]>nid[v])swap(u,v);
            if(fst[u]!=fst[v]){
                //[nid[fst[v]],nid[v]];
                v=par[fst[v]];
            }else{
                //if(u!=v)[nid[u]+1,nid[v]];
                break;
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
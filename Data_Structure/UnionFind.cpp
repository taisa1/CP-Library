struct UnionFind{
    vector<int> par;
    vector<int> dep;
    
    UnionFind(int siz){
        par.assign(siz,0);
        dep.assign(siz,0);
        for(int i=0;i<siz;i++){
            par[i]=i;
        }
    };

    int find(int x){
        if(par[x]==x){
            return x;
        }else{
            return par[x]=find(par[x]);
        }
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return;
        }
        if(dep[x]<dep[y]){
            par[x]=y;
        }else{
            par[y]=x;
            if(dep[x]==dep[y]){
                dep[x]++;
            }
        }
    }

    bool same(int x,int y){
        return find(x)==find(y);
    }
};
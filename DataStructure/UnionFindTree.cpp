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
    bool unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return false;
        }
        if(dep[x]<dep[y]){
            par[x]=y;
        }else{
            par[y]=x;
            if(dep[x]==dep[y]){
                dep[x]++;
            }
        }
        return true;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
};
vector<P> tree;
vector<P> siz[100010];
struct PartiallyPersistentUnionFind{
    int t=0;
    int find(int v,int x){
        while(tree[x].second<=v){
            x=tree[x].first;
        }
        return x;
    }
    bool unite(int x,int y){
        t++;
        x=find(t,x);
        y=find(t,y);
        if(x==y){
            return false;
        }
        if(tree[x].first<tree[y].first){
            swap(x,y);
        }
        tree[x].first+=tree[y].first;
        siz[x].push_back(P(t,tree[x].first));
        tree[y]=P(x,t);
        return true;
    }
    int size(int v,int x){
        x=find(v,x);
        return (lower_bound(all(siz[x]),P(v+1,0))-1)->second;
    }
    bool same(int v,int x,int y){
        return find(v,x)==find(v,y);
    }
};
struct PartiallyPersistentUnionFind{
    int now=0;
    struct vertex{int siz,par,tim;};
    vector<vertex> tree;
    PartiallyPersistentUnionFind(int n){
        now=0;
        for(int i=0;i<n;i++)tree.push_back({1,1,1<<30});
    }
    int find(int x,int t){  
        while(tree[x].tim<=t){
            x=tree[x].par;
        }
        return x;
    }
    bool unite(int u,int v){
        ++now;
        u=find(u,now),v=find(v,now);
        if(u==v)return false;
        if(tree[u].siz<tree[v].siz)swap(u,v);
        tree[v].par=u;
        tree[v].tim=now;
        tree[u].siz+=tree[v].siz;
        return true;
    }
    bool same(int u,int v,int t){
        return find(u,t)==find(v,t);
    }
};
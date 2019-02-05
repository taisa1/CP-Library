struct UnionFind{
    vector<int> par,siz;
    UnionFind(int n){
        par.resize(n);
        siz.resize(n,1);
		for(int i=0;i<n;i++)par[i]=i;
    }
    int find(int x){
		if(par[x]==x){
			return x;
		}else{
			return par[x]=find(par[x]);
		}
	}
	bool unite(int u,int v){
		u=find(u),v=find(v);
		if(u==v)return false;
		if(siz[u]<siz[v])swap(u,v);
		par[v]=u;
		siz[u]+=siz[v];
		return true;
	}
	bool same(int u,int v){
		return find(u)==find(v);
	}
};
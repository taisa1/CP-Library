template <typename Monoid>
struct Segtree{
	using func=function<Monoid(Monoid,Monoid)>;
	int n;
	Monoid init;//単位元
	vector<Monoid> node;
	func f;//二項演算
	Segtree(int n_,const Monoid &init,const func f):init(init),f(f){
		n=1;
		while(n<n_)n<<=1;
		node.assign(2*n,init);
	}
	void update(int k,const Monoid &x){
		k+=n;
		node[k]=x;
		for(k>>=1;k>0;k>>=1){
			node[k]=f(node[k<<1],node[k<<1|1]);
		}
	}
	Monoid query(int l,int r){//[l,r)
		Monoid res=init;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1){
				res=f(res,node[l]);
				l++;
			}
			if(r&1){
				r--;
				res=f(res,node[r]);
			}
		}
		return res;
	}
};
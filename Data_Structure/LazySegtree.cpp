template<typename Monoid,typename Operator=Monoid>
struct Segtree{
    using F=function<Monoid(Monoid,Monoid)>;
	using G=function<Monoid(Monoid,Operator,int)>;
	using H=function<Operator(Operator,Operator)>;
	int n;
	const Monoid m;
	const Operator o;
	const F f;
	const G g;
	const H h;
	vector<Monoid> node;
	vector<Operator> lazy;
	Segtree(int n_,const Monoid& m,const Operator& o,const F f,const G g,const H h):m(m),o(o),f(f),g(g),h(h){
		n=1;
		while(n<n_)n<<=1;
		node.assign(2*n,m);
		lazy.assign(2*n,o);
	}
	Monoid opmo()
	void eval(int k,int len){
		if(lazy[k]==o)return;
		node[k]=g(node[k],lazy[k],len);
		if(len>1){
			lazy[k<<1]=h(lazy[k<<1],lazy[k]);
			lazy[k<<1|1]=h(lazy[k<<1|1],lazy[k]);
		}
		lazy[k]=o;
	}
	void update(int l,int r,Operator x){
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1){
				lazy[l]=h(lazy[l],x);
				l++;
			}
			if(r&1){
				r--;
				lazy[r]=h(lazy[r],x);
			}
		}
	}
	Monoid query(int l,int r){
		Monoid res=m;
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
}

template<typename T,typename E>
struct Segtree{
    using F=function<T(T,T)>;
    using G=function<T(T,E,int)>;
    using H=function<E(E,E)>;
    int n,hi;
    const T t;
    const E e;
    const F f;
    const G g;
    const H h;
    vector<T> node;
    vector<E> lazy;
    vector<int> len;
    Segtree(int n_,const T& t,const E& e,const F f,const G g,const H h):t(t),e(e),f(f),g(g),h(h){
        n=1,hi=1;
        while(n<n_)n<<=1,++hi;
        node.assign(2*n,t);
        lazy.assign(2*n,e);
        len.assign(2*n,1);
        for(int i=n-1;i>=1;i--){
            len[i]=len[i<<1]+len[i<<1|1];
        }
    }
    T eval(int k){
        node[k]=g(node[k],lazy[k],len[k]);
        if(lazy[k]==e)return node[k];
        if(k<n){
            lazy[k<<1]=h(lazy[k<<1],lazy[k]);
            lazy[k<<1|1]=h(lazy[k<<1|1],lazy[k]);
        }
        lazy[k]=e;
        return node[k];
    }
    void update(int a,int b,const E& x){//[a,b]->[a,b)
        int l=a+n,r=b+n;
		for(int i=hi;i>0;i--)eval(l>>i),eval(r>>i);
        for(++r;l<r;l>>=1,r>>=1){
            if(l&1)lazy[l]=h(lazy[l],x),l++;
            if(r&1)--r,lazy[r]=h(lazy[r],x);
        }
        l=a+n,r=b+n;
        while(l>>=1)node[l]=f(eval(l<<1),eval(l<<1|1));
        while(r>>=1)node[r]=f(eval(r<<1),eval(r<<1|1));
    }
    T query(int a,int b){//[a,b]->[a,b)
        int l=a+n,r=b+n;
        for(int i=hi;i>0;i--)eval(l>>i),eval(r>>i);
        T vl=t,vr=t;
        for(++r;l<r;l>>=1,r>>=1){
            if(l&1)vl=f(vl,eval(l++));
            if(r&1)vr=f(eval(--r),vr);
        }
        return f(vl,vr);
    }
};

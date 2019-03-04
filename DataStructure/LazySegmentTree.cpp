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
    vector<T> dat;
    vector<E> laz;
    vector<int> len;
    Segtree(int n_,const T& t,const E& e,const F f,const G g,const H h):t(t),e(e),f(f),g(g),h(h){
        n=1,hi=1;
        while(n<n_)n<<=1,++hi;
        dat.assign(2*n,t);
        laz.assign(2*n,e);
        len.assign(2*n,1);
        for(int i=n-1;i>=1;i--){
            len[i]=len[i<<1]+len[i<<1|1];
        }
    }
    T prop(int k){
        dat[k]=g(dat[k],laz[k],len[k]);
        if(laz[k]==e)return dat[k];
        if(k<n){
            laz[k<<1]=h(laz[k<<1],laz[k]);
            laz[k<<1|1]=h(laz[k<<1|1],laz[k]);
        }
        laz[k]=e;
        return dat[k];
    }
    void update(int a,int b,const E& x){//[a,b]->[a,b)
        int l=a+n,r=b+n;
		for(int i=hi;i>0;i--)prop(l>>i),prop(r>>i);
        for(++r;l<r;l>>=1,r>>=1){
            if(l&1)laz[l]=h(laz[l],x),l++;
            if(r&1)--r,laz[r]=h(laz[r],x);
        }
        l=a+n,r=b+n;
        while(l>>=1)dat[l]=f(prop(l<<1),prop(l<<1|1));
        while(r>>=1)dat[r]=f(prop(r<<1),prop(r<<1|1));
    }
    T query(int a,int b){//[a,b]->[a,b)
        int l=a+n,r=b+n;
        for(int i=hi;i>0;i--)prop(l>>i),prop(r>>i);
        T vl=t,vr=t;
        for(++r;l<r;l>>=1,r>>=1){
            if(l&1)vl=f(vl,prop(l++));
            if(r&1)vr=f(prop(--r),vr);
        }
        return f(vl,vr);
    }
};

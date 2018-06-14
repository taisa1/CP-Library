struct SegmentTree{
    int siz;
    vector<ll> node;
    SegmentTree(int n,ll init){
        siz=1;
        while(siz<n)siz<<=1;
        node.assign(2*siz,init);
    }

    void update(int k,ll x){
        k+=siz-1;
        node[k]=x;
        while(k>0){
            k=(k-1)/2;
            node[k]=min(node[2*k+1],node[2*k+2]);
        }
    }

    ll query(int a,int b,int k=0,int l=0,int r=-1){
        if(r<0)r=siz;
        if(r<=a||b<=l)return LINF;
        if(a<=l&&r<=b)return node[k];
        ll vl=query(a,b,2*k+1,l,(l+r)/2);
        ll vr=query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
};
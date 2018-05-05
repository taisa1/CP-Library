struct SegmentTree{
    int siz;
    vector<int> node;
    SegmentTree(int n,int init){
        siz=1;
        while(siz<n)siz<<=1;
        node.assign(2*siz,init);
    }

    void update(int k,int x){
        k+=siz-1;
        node[k]+=x;
        while(k>0){
            k=(k-1)/2;
            node[k]=min(node[2*k+1],node[2*k+2]);
        }
    }

    int query(int a,int b,int k=0,int l=0,int r=-1){
        if(r<0)r=siz;
        if(r<=a||b<=l)return INF;
        if(a<=l&&r<=b)return node[k];
        int vl=query(a,b,2*k+1,l,(l+r)/2);
        int vr=query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
};
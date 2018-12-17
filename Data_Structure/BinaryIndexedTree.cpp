template <typename T>
struct BinaryIndexedTree{
    vector<T> node;
    int n;
    BinaryIndexedTree(int n):n(n){
        node.assign(++n,0);
    }
    void add(int k,T x){
        for(++k;k<n;k+=k&-k){
            node[k]+=x;
        }
    }
    T sum(int k){
        T res=0;
        for(++k;k>0;k-=k&-k){
            res+=node[k];
        }
        return res;
    }
};
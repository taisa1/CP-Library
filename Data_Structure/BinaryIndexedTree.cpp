struct BinaryIndexedTree{
    vector<int> bit;
    BinaryIndexedTree(int siz){
        bit.assign(++siz,0);
    }

    int sum(int k){
        int ret=0;
        for(++k;k>0;k-=k&-k){
            ret+=bit[k];
        }
        return ret;
    }

    void add(int k,int x){
        for(++k;k<bit.size();k+=k&-k){
            bit[k]+=x;
        }
    }
};
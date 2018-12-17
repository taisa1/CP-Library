template<typename T>
struct PriorityQueue{
    using F=function<bool(T,T)>;
    i32 n;
    vector<T> node;
    F f;
    PriorityQueue(F f):n(0),f(f){node.resize(1);};
    void push(const T& x){
        ++n;
        if(node.size()>n){
            node[n]=x;
        }else{
            node.emplace_back(x);
        }
        i32 k=n;
        while(k>1){
            if(f(node[k],node[k>>1])){
                swap(node[k],node[k>>1]);
                k>>=1;
            }else{
                break;
            }
        }
    }
    void pop(){
        node[1]=node[n];
        --n;
        i32 k=1;
        while((k<<1)<=n){
            if((k<<1|1)>n){
                if(f(node[k<<1],node[k]))swap(node[k],node[k<<1]);
                break;
            }
            if(f(node[k<<1],node[k<<1|1])&&f(node[k<<1],node[k])){
                swap(node[k],node[k<<1]);
                k<<=1;
            }else if(f(node[k<<1|1],node[k])){
                swap(node[k],node[k<<1|1]);
                k<<=1,++k;
            }else{
                break;
            }
        }   
    }
    T top(){
        assert(node.size()>1);
        return node[1];
    }
    bool empty(){
        return n<1;
    }
};
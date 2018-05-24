vector<int> toposort(int n,vector<int>[] G,int[] h){
    stack<int> st;
    vector<int> res;
    for(int i=0;i<n;i++){
        if(!h[i])st.push(i);
    }
    while(!st.empty()){
        int id=st.top();
        st.pop();
        res.push_back(id);
        for(auto e:G[id]){
            h[e]--;
            if(!h[e])st.push(e);
        }
    }
    return res;
}
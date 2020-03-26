template <class T>
struct Median {
    priority_queue<T> smq;
    priority_queue<T, vector<T>, greater<T>> lgq;
    void push(T x) {
        if (smq.empty()) {
            smq.push(x);
            return;
        }
        T t = smq.top();
        if (smq.size() > lgq.size()) {
            if (t <= x) {
                lgq.push(x);
            } else {
                lgq.push(t);
                smq.pop();
                smq.push(x);
            }
        } else {
            if (t >= x) {
                smq.push(x);
            } else {
                lgq.push(x);
                smq.push(lgq.top());
                lgq.pop();
            }
        }
    }
    inline T get() { return smq.top(); }
};
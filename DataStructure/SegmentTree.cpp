template <typename T>
struct Segtree {
    using F = function<T(T, T)>;
    int n;
    vector<T> node;
    const F f;
    const T t;
    Segtree(int n_, const T& t, const F f) : t(t), f(f) {
        n = 1;
        while(n < n_) n <<= 1;
        node.assign(2 * n, t);
    }
    void update(int k, const T& x) {
        k += n;
        node[k] = x;
        for(k >>= 1; k > 0; k >>= 1) {
            node[k] = f(node[k << 1], node[k << 1 | 1]);
        }
    }
    T query(int a, int b) {  //[a,b]->[a,b)
        T vl = t, vr = t;
        int l = a + n, r = b + n + 1;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) vl = f(vl, node[l++]);
            if(r & 1) vr = f(node[--r], vr);
        }
        return f(vl, vr);
    }
};
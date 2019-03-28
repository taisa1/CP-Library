template <class Monoid>
struct Segtree {
    int n;
    vector<T> dat;
    Segtree(int n_) {
        n = 1;
        while(n < n_) n <<= 1;
        dat.resize(2 * n, Monoid::id());
    }
    T get(int k) {
        assert(k < n);
        return dat[k + n];
    }
    void set(int k, const T& x) {
        assert(k < n);
        k += n;
        dat[k] = x;
        for(k >>= 1; k > 0; k >>= 1) {
            dat[k] = Monoid::op(dat[k << 1], dat[k << 1 | 1]);
        }
    }
    T query(int a, int b) {  //[a,b]->[a,b)
        if(a < 0) a = 0;
        if(a > b) return Monoid::id();
        if(b > n) b = n;
        T vl = Monoid::id(), vr = Monoid::id();
        int l = a + n, r = b + n + 1;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) vl = Monoid::op(vl, dat[l++]);
            if(r & 1) vr = Monoid::op(dat[--r], vr);
        }
        return Monoid::op(vl, vr);
    }
};
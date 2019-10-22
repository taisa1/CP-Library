template <typename T, typename E> struct Segtree {
    inline T merge(const T &a, const T &b) { return min(a, b); }
    inline void act(E &a, const E &b) { a = b; }
    inline void comb(T &a, const E &b) { a = b; }
    int n;
    T et;
    E ee;
    vector<T> dat;
    vector<E> laz;
    Segtree(int n_, T et, E ee) : et(et), ee(ee) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, et);
        laz.resize(2 * n, ee);
    }
    void eval(int k) {
        if (laz[k] == ee) {
            return;
        }
        comb(dat[k], laz[k]);
        if (k < n) {
            act(laz[k << 1], laz[k]);
            act(laz[k << 1 | 1], laz[k]);
        }
        laz[k] = ee;
    }
    void upd(const int &a, const int &b, const E &x, int k, int l, int r) {
        if (b <= l || r <= a) {
            return;
        }
        eval(k);
        if (a <= l && r <= b) {
            act(laz[k], x);
            return;
        }
        upd(a, b, x, k << 1, l, (l + r) >> 1);
        upd(a, b, x, k << 1 | 1, (l + r) >> 1, r);
        dat[k] = merge(dat[k << 1], dat[k << 1 | 1]);
    }
    inline void upd(const int &a, const int &b, const E &x) {
        if (a >= b) {
            return;
        }
        upd(a, b, x, 1, 0, n);
    }
    T get(const int &a, const int &b, int k, int l, int r) {
        if (b <= l || r <= a) {
            return et;
        }
        eval(k);
        if (a <= l && r <= b) {
            return dat[k];
        }
        return merge(get(a, b, k << 1, l, (l + r) >> 1),
                     get(a, b, k << 1 | 1, (l + r) >> 1, r));
    }
    inline T get(const int &a, const int &b) {
        if (a >= b) {
            return et;
        }
        return get(a, b, 1, 0, n);
    }
};
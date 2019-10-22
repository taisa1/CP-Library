template <typename T> struct Segtree {
    inline T merge(const T &a, const T &b) { return min(a, b); }
    inline void act(T &a, const T &b) { a = b; }
    int n;
    T e;
    vector<T> dat;
    Segtree(int n_, T e) : e(e) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n);
    }
    void upd(int k, const T &x) {
        k += n;
        act(dat[k], x);
        k >>= 1;
        while (k > 0) {
            dat[k] = merge(dat[k << 1], dat[k << 1 | 1]);
            k >>= 1;
        }
    }
    T get(const int &a, const int &b, int k, int l, int r) {
        if (b <= l || r <= a) {
            return e;
        }
        if (a <= l && r <= b) {
            return dat[k];
        }
        return merge(get(a, b, k << 1, l, (l + r) >> 1),
                     get(a, b, k << 1 | 1, (l + r) >> 1, r));
    }
    inline void get(const int &a, const int &b) { //[a,b)
        if (a >= b) {
            return e;
        }
        return get(a, b, 1, 0, n);
    }
    int find(const int &a, const int &b, const T &x, int k, int l, int r) {
        if (b <= l || r <= a || dat[k] > x) {
            return -1;
        }
        if (k >= n) {
            return k - n;
        }
        int il = find(a, b, x, k << 1, l, (l + r) >> 1);
        if (il != -1) {
            return il;
        }
        return find(a, b, x, k << 1 | 1, (l + r) >> 1, r);
    }
    inline int find(const int &a, const int &b, const T &x) {
        if (a >= b) {
            return -1;
        }
        return find(a, b, x, 1, 0, n);
    }
};
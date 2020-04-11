//Range Update Point Get
template <typename T>
struct Segtree {
    inline T merge(T a, T b) { return a + b; }
    inline void act(T &a, T b) { a += b; }
    vector<T> dat;
    int n;
    T e;
    Segtree(int n_, T e) : e(e) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, e);
    }
    void upd(const int &a, const int &b, const T &x, int k, int l, int r) {
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            act(dat[k], x);
            return;
        }
        set(a, b, x, k << 1, l, (l + r) >> 1);
        set(a, b, x, k << 1 | 1, (l + r) >> 1, r);
    }
    inline void upd(const int &a, const int &b, const T &x) {
        if (a >= b) {
            return;
        }
        set(a, b, x, 1, 0, n);
    }
    T get(int k) {
        k += n;
        T res = dat[k];
        k >>= 1;
        while (k > 0) {
            res = merge(res, dat[k]);
            k >>= 1;
        }
        return res;
    }
};

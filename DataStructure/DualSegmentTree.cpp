//Range Update Point Get
template <class T>
struct Segtree {
    vector<T> dat;
    int n;
    T e;
    Segtree(int n_) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, T::id());
    }
    void upd(const int &a, const int &b, const T &x, int k, int l, int r) {
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            dat[k] = T::g(dat[k], x);
            return;
        }
        upd(a, b, x, k << 1, l, (l + r) >> 1);
        upd(a, b, x, k << 1 | 1, (l + r) >> 1, r);
    }
    inline void upd(const int &a, const int &b, const T &x) {
        if (a >= b) {
            return;
        }
        upd(a, b, x, 1, 0, n);
    }
    T get(int k) {
        k += n;
        T res = dat[k];
        k >>= 1;
        while (k > 0) {
            res = T::f(res, dat[k]);
            k >>= 1;
        }
        return res;
    }
};

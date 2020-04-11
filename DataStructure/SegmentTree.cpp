//Point Update Range Get
template <class T>
struct Segtree {
    inline T f(const T &a, const T &b) { return b * a; }
    inline void act(T &a, const T &b) { a = b; }
    int n;
    T e;
    vector<T> dat;
    Segtree(int n_, T e) : e(e) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, e);
    }
    Segtree(int n_, const T &e, const vector<T> &a) : e(e) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, e);
        for (int i = 0; i < a.size(); i++) {
            dat[i + n] = a[i];
        }
        for (int i = n - 1; i > 0; i--) {
            dat[i] = f(dat[i << 1], dat[i << 1 | 1]);
        }
    }
    void upd(int k, const T &x) {
        k += n;
        act(dat[k], x);
        k >>= 1;
        while (k > 0) {
            dat[k] = f(dat[k << 1], dat[k << 1 | 1]);
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
        return f(get(a, b, k << 1, l, (l + r) >> 1),
                 get(a, b, k << 1 | 1, (l + r) >> 1, r));
    }
    inline T get(const int &a, const int &b) { //[a,b)
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
    inline int find(const int &a, const int &b, const T &x) { //[a,b)における、値<=x なる最左のindexを求める
        if (a >= b) {
            return -1;
        }
        return find(a, b, x, 1, 0, n);
    }
};
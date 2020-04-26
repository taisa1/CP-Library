//@docs Docs/LazySegmentTree.md
template <class T, class E>
struct Segtree {
    int n, h;
    vector<T> dat;
    vector<E> laz;
    vector<ll> len;
    Segtree(int n_) {
        n = 1;
        h = 1;
        while (n < n_) {
            n <<= 1;
            h++;
        }
        dat.resize(2 * n, T::id());
        laz.resize(2 * n, E::id());
        len.resize(2 * n, 1);
        for (int i = n - 1; i > 0; i--) len[i] = len[i << 1] + len[i << 1 | 1];
    }
    Segtree(int n_, const vector<T> &a) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, T::id());
        laz.resize(2 * n, E::id());
        len.resize(2 * n, 1);
        for (int i = 0; i < a.size(); i++) dat[i + n] = a[i];
        for (int i = n - 1; i > 0; i--) {
            len[i] = len[i << 1] + len[i << 1 | 1];
            dat[i] = T::f(dat[i << 1], dat[i << 1 | 1]);
        }
    }
    inline void eval(int k) {
        dat[k] = T::g(dat[k], laz[k], len[k]);
        if (k < n) {
            laz[k << 1] = E::f(laz[k << 1], laz[k]);
            laz[k << 1 | 1] = E::f(laz[k << 1 | 1], laz[k]);
        }
        laz[k] = E::id();
    }
    void upd(const int &a, const int &b, const E &x, int k, int l, int r) {
        eval(k);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            laz[k] = E::f(laz[k], x);
            eval(k);
            return;
        }
        upd(a, b, x, k << 1, l, (l + r) >> 1);
        upd(a, b, x, k << 1 | 1, (l + r) >> 1, r);
        dat[k] = T::f(dat[k << 1], dat[k << 1 | 1]);
    }
    T get(const int &a, const int &b, int k, int l, int r) {
        eval(k);
        if (b <= l || r <= a) {
            return T::id();
        }
        if (a <= l && r <= b) {
            return dat[k];
        }
        return T::f(get(a, b, k << 1, l, (l + r) >> 1), get(a, b, k << 1 | 1, (l + r) >> 1, r));
    }
    int find(const int &a, const int &b, const T &x, int k, int l, int r) {
        eval(k);
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
    void setval(int k, const T &x) {
        k += n;
        for (int i = h; i >= 0; i--) eval(k >> i);
        dat[k] = x;
        while (k > 1) {
            k >>= 1;
            dat[k] = T::f(dat[k << 1], dat[k << 1 | 1]);
        }
    }
    inline void upd(const int &a, const int &b, const E &x) {
        if (a >= b) {
            return;
        }
        upd(a, b, x, 1, 0, n);
    }
    inline T get(const int &a, const int &b) {
        if (a >= b) {
            return T::id();
        }
        return get(a, b, 1, 0, n);
    }
    inline int find(const int &a, const int &b, const T &x) { //[a,b)における、値<=x なる最左のindexを求める
        if (a >= b) {
            return -1;
        }
        return find(a, b, x, 1, 0, n);
    }
};
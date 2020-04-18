//Range Update Range Get
template <class T, class E>
struct Segtree {
    int n;
    vector<T> dat;
    vector<E> laz;
    vector<ll> len;
    Segtree(int n_) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, T::e);
        laz.resize(2 * n, E::e);
        len.resize(2 * n, 1);
        for (int i = n - 1; i > 0; i--) len[i] = len[i << 1] + len[i << 1 | 1];
    }
    Segtree(int n_, const vector<T> &a) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, T::e);
        laz.resize(2 * n, E::e);
        len.resize(2 * n, 1);
        for (int i = 0; i < a.size(); i++) dat[i + n] = a[i];
        for (int i = n - 1; i > 0; i--) {
            len[i] = len[i << 1] + len[i << 1 | 1];
            dat[i] = T::f(dat[i << 1], dat[i << 1 | 1]);
        }
    }
    inline void eval(int k) {
        dat[k].g(laz[k], len[k]);
        if (k < n) {
            laz[k << 1].h(laz[k]);
            laz[k << 1 | 1].h(laz[k]);
        }
        laz[k] = E::e;
    }
    void upd(const int &a, const int &b, const E &x, int k, int l, int r) {
        eval(k);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            laz[k].h(x);
            eval(k);
            return;
        }
        upd(a, b, x, k << 1, l, (l + r) >> 1);
        upd(a, b, x, k << 1 | 1, (l + r) >> 1, r);
        dat[k] = T::f(dat[k << 1], dat[k << 1 | 1]);
    }
    inline void upd(const int &a, const int &b, const E &x) {
        if (a >= b) {
            return;
        }
        upd(a, b, x, 1, 0, n);
    }
    T get(const int &a, const int &b, int k, int l, int r) {
        eval(k);
        if (b <= l || r <= a) {
            return T::e;
        }
        if (a <= l && r <= b) {
            return dat[k];
        }
        return T::f(get(a, b, k << 1, l, (l + r) >> 1), get(a, b, k << 1 | 1, (l + r) >> 1, r));
    }
    inline T get(const int &a, const int &b) {
        if (a >= b) {
            return T::e;
        }
        return get(a, b, 1, 0, n);
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
    inline int find(const int &a, const int &b, const T &x) { //[a,b)における、値<=x なる最左のindexを求める
        if (a >= b) {
            return -1;
        }
        return find(a, b, x, 1, 0, n);
    }
};
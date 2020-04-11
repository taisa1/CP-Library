//Line Add Get Min
struct T {
    ll a, b;
};
struct CHT {
    struct T {
        ll a, b;
    };
    vector<T> dat;
    vector<ll> xs;
    int n;
    void preadd(ll x) {
        xs.eb(x);
    }
    void build() {
        sort(all(xs));
        xs.erase(unique(all(xs)), xs.end());
        n = 1;
        while (n < xs.size()) {
            n <<= 1;
        }
        while (xs.size() < n) {
            xs.eb(1LL << 30);
        }
        dat.resize(2 * n, T{0, INF});
    }
    inline ll f(T &a, ll x) {
        return a.a * x + a.b;
    }
    void add(T &a, int k, int l, int r) {
        ll vl = f(dat[k], xs[l]), vl2 = f(a, xs[l]), vr = f(dat[k], xs[r - 1]), vr2 = f(a, xs[r - 1]);
        if (vl <= vl2 && vr <= vr2) return;
        if (vl2 <= vl && vr2 <= vr) {
            dat[k] = a;
            return;
        }
        if (r - l <= 1) return;
        int m = (l + r) / 2;
        if (vl2 < vl) swap(dat[k], a);
        ll vm = f(dat[k], xs[m]), vm2 = f(a, xs[m]);
        if (vm2 < vm) {
            swap(dat[k], a);
            add(a, k << 1, l, m);
        } else {
            add(a, k << 1 | 1, m, r);
        }
    }
    void add(ll a, ll b) {
        T t = T{a, b};
        add(t, 1, 0, n);
    }
    ll get(ll x) {
        int k = lower_bound(all(xs), x) - xs.begin();
        k += n;
        ll res = f(dat[k], x);
        k >>= 1;
        while (k > 0) {
            chmin(res, f(dat[k], x));
            k >>= 1;
        }
        return res;
    }
};
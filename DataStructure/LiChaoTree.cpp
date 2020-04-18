struct T {
    ll a, b;
};
struct CHT {
    int n;
    vector<T> dat;
    vector<ll> xs;
    void preadd(ll x) {
        xs.emplace_back(x);
    }
    void build() {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        n = 1;
        while (n < xs.size()) n <<= 1;
        dat.resize(2 * n, T{0, INF});
        ll en = xs.back() + 1;
        while (xs.size() < n) {
            xs.emplace_back(en);
            en++;
        }
    }
    ll f(T &a, ll x) {
        return a.a * x + a.b;
    }
    void add(T a, int k, int l, int r) {
        ll vl1 = f(dat[k], xs[l]), vl2 = f(a, xs[l]), vr1 = f(dat[k], xs[r - 1]), vr2 = f(a, xs[r - 1]);
        if (vl1 <= vl2 && vr1 <= vr2) return;
        if (vl2 <= vl1 && vr2 <= vr1) {
            dat[k] = a;
            return;
        }
        if (r - l == 1) return;
        if (vl1 > vl2) swap(dat[k], a);
        int m = (l + r) / 2;
        ll vm1 = f(dat[k], xs[m]), vm2 = f(a, xs[m]);
        if (vm2 < vm1) {
            swap(dat[k], a);
            add(a, k << 1, l, m);
        } else {
            add(a, k << 1 | 1, m, r);
        }
    }
    inline void add(ll a, ll b) { add(T{a, b}, 1, 0, n); }
    ll get(ll x) {
        int k = lower_bound(all(xs), x) - xs.begin();
        k += n;
        ll res = INF;
        while (k > 0) {
            res = min(res, f(dat[k], x));
            k >>= 1;
        }
        return res;
    }
};
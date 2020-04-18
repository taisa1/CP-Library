---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: DataStructure/LiChaoTree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/LiChaoTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 13:22:22+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/LineCHT.test.cpp.html">Test/LineCHT.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/LiChaoTree.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


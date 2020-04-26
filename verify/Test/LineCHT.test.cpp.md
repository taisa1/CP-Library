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


# :heavy_check_mark: Test/LineCHT.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/LineCHT.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 01:54:08+09:00


* see: <a href="https://judge.yosupo.jp/problem/line_add_get_min">https://judge.yosupo.jp/problem/line_add_get_min</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/LiChaoTree.cpp.html">DataStructure/LiChaoTree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define fs first
#define sc second
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
constexpr ll INF = (1LL << 62) - 1LL;
constexpr ll MOD = 998244353LL;
constexpr int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
template <class T>
void chmin(T &a, T b) { a = min(a, b); }
template <class T>
void chmax(T &a, T b) { a = max(a, b); }
void debug() { cerr << "ok" << endl; }
template <class T>
void printv(const vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
}
#define call_from_test
#include "../DataStructure/LiChaoTree.cpp"
#undef call_from_test
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n), t(q), p(q), c(q), d(q);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    CHT cht;
    for (int i = 0; i < q; i++) {
        cin >> t[i];
        if (t[i] == 0) {
            cin >> c[i] >> d[i];
        } else {
            cin >> p[i];
            cht.preadd(p[i]);
        }
    }
    cht.build();
    for (int i = 0; i < n; i++) {
        cht.add(a[i], b[i]);
    }
    for (int i = 0; i < q; i++) {
        if (t[i] == 0) {
            cht.add(c[i], d[i]);
        } else {
            cout << cht.get(p[i]) << '\n';
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/LineCHT.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define fs first
#define sc second
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
constexpr ll INF = (1LL << 62) - 1LL;
constexpr ll MOD = 998244353LL;
constexpr int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
template <class T>
void chmin(T &a, T b) { a = min(a, b); }
template <class T>
void chmax(T &a, T b) { a = max(a, b); }
void debug() { cerr << "ok" << endl; }
template <class T>
void printv(const vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
}
#define call_from_test
#line 1 "DataStructure/LiChaoTree.cpp"
//@docs Docs/LiChaoTree.md
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
#line 27 "Test/LineCHT.test.cpp"
#undef call_from_test
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n), t(q), p(q), c(q), d(q);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    CHT cht;
    for (int i = 0; i < q; i++) {
        cin >> t[i];
        if (t[i] == 0) {
            cin >> c[i] >> d[i];
        } else {
            cin >> p[i];
            cht.preadd(p[i]);
        }
    }
    cht.build();
    for (int i = 0; i < n; i++) {
        cht.add(a[i], b[i]);
    }
    for (int i = 0; i < q; i++) {
        if (t[i] == 0) {
            cht.add(c[i], d[i]);
        } else {
            cout << cht.get(p[i]) << '\n';
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


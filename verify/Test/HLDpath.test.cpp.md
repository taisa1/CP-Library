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


# :heavy_check_mark: Test/HLDpath.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/HLDpath.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 20:12:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/vertex_add_path_sum">https://judge.yosupo.jp/problem/vertex_add_path_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/BinaryIndexedTree.cpp.html">DataStructure/BinaryIndexedTree.cpp</a>
* :heavy_check_mark: <a href="../../library/Graph/HeavyLightDecomposition.cpp.html">Graph/HeavyLightDecomposition.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
constexpr ll INF = (1LL << 30) - 1LL;
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
template <class T>
void readv(vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}
#define call_from_test
#include "../DataStructure/BinaryIndexedTree.cpp"
#include "../Graph/HeavyLightDecomposition.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    V<ll> a(n);
    readv(a);
    HLD g(n);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v);
    }
    BinaryIndexedTree<ll> bit(n);
    for (int i = 0; i < n; i++) {
        bit.add(g.index(i), a[i]);
    }
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            bit.add(g.index(u), v);
        } else {
            ll res = 0;
            auto f = [&](int a, int b) { res += bit.get(a, b); };
            g.getpath(u, v, f);
            cout << res << '\n';
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/HLDpath.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
constexpr ll INF = (1LL << 30) - 1LL;
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
template <class T>
void readv(vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}
#define call_from_test
#line 1 "DataStructure/BinaryIndexedTree.cpp"
//Point Add Range Sum
template <class T>
struct BinaryIndexedTree {
    int n;
    vector<T> dat;
    BinaryIndexedTree(const int &n) : n(n + 1), dat(n + 1) {}
    void add(int k, const T &x) {
        for (++k; k < n; k += k & -k) dat[k] += x;
    }
    T get(int k) {
        T res = 0;
        for (++k; k > 0; k -= k & -k) res += dat[k];
        return res;
    }
    inline T get(const int &l, const int &r) { //0-indexed [l,r)
        return get(r - 1) - get(l - 1);
    }
};
#line 1 "Graph/HeavyLightDecomposition.cpp"
//Path Sum and Subtree Sum
struct HLD {
    int n;
    vector<vector<int>> G;
    vector<int> sz, rt, id, par, out;
    int pos, cnt;
    HLD(int n) : n(n), G(n), sz(n, 1), rt(n, -1), id(n), par(n, -1), out(n), cnt(0) {}
    void addedge(const int &u, const int &v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        cnt++;
        if (cnt == n - 1) {
            build();
        }
    }
    void build() {
        szdfs(0, -1);
        id[0] = 0;
        rt[0] = 0;
        pos = 0;
        hld(0, -1);
    }
    void szdfs(int i, int p) {
        for (auto &e : G[i]) {
            if (e == p) continue;
            szdfs(e, i);
            par[e] = i;
            sz[i] += sz[e];
            if (sz[e] > sz[G[i][0]]) {
                swap(G[i][0], e);
            }
        }
    }
    void hld(int i, int p) {
        id[i] = pos;
        pos++;
        for (auto &e : G[i]) {
            if (e == p) continue;
            if (e == G[i][0]) {
                rt[e] = rt[i];
            } else {
                rt[e] = e;
            }
            hld(e, i);
        }
        out[i] = pos;
    }
    template <class F>
    void getpath(int u, int v, const F &f) { //f:[a,b)
        while (1) {
            if (id[u] > id[v]) swap(u, v);
            if (rt[u] == rt[v]) {
                f(id[u], id[v] + 1);
                break;
            } else {
                f(id[rt[v]], id[v] + 1);
                v = par[rt[v]];
            }
        }
    }
    template <class F>
    void getsubtree(const int &u, const F &f) { //f:[a,b)
        f(id[u], out[u]);
    }
    inline int index(const int &i) {
        return id[i];
    }
};
#line 32 "Test/HLDpath.test.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    V<ll> a(n);
    readv(a);
    HLD g(n);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v);
    }
    BinaryIndexedTree<ll> bit(n);
    for (int i = 0; i < n; i++) {
        bit.add(g.index(i), a[i]);
    }
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            bit.add(g.index(u), v);
        } else {
            ll res = 0;
            auto f = [&](int a, int b) { res += bit.get(a, b); };
            g.getpath(u, v, f);
            cout << res << '\n';
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


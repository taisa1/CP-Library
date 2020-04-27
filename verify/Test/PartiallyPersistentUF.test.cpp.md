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


# :heavy_check_mark: Test/PartiallyPersistentUF.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/PartiallyPersistentUF.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 12:42:37+09:00


* see: <a href="https://yukicoder.me/problems/no/416">https://yukicoder.me/problems/no/416</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/PartiallyPersistentUnionFind.cpp.html">DataStructure/PartiallyPersistentUnionFind.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/416"
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
#define call_from_test
#include "../DataStructure/PartiallyPersistentUnionFind.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    set<P> st;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        st.insert(P(a, b));
    }
    V<int> c(q), d(q);
    for (int i = 0; i < q; i++) {
        cin >> c[i] >> d[i];
        --c[i];
        --d[i];
        st.erase(P(c[i], d[i]));
    }
    UnionFind uf(n);
    for (auto &e : st) {
        uf.unite(e.first, e.second, 0);
    }
    for (int i = q - 1; i >= 0; i--) {
        uf.unite(c[i], d[i], q - i);
    }
    for (int i = 1; i < n; i++) {
        if (uf.same(0, i, 0)) {
            cout << -1 << '\n';
            continue;
        }
        if (!uf.same(0, i, q)) {
            cout << 0 << '\n';
            continue;
        }
        int ok = 0, ng = q;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (uf.same(0, i, q - mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << ok + 1 << '\n';
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/PartiallyPersistentUF.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/416"
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
#define call_from_test
#line 1 "DataStructure/PartiallyPersistentUnionFind.cpp"
//@docs Docs/PartiallyPersistentUnionFind.md
struct UnionFind {
    vector<int> par, sz, tim;
    UnionFind(int n) : par(n), sz(n, 1), tim(n, -1) {
        iota(par.begin(), par.end(), 0);
    }
    //時刻tのuniteの後のrootを求める
    inline int find(int x, int t) {
        while (par[x] != x && tim[x] <= t) x = par[x];
        return x;
    }
    //与えられるtは広義単調増加
    bool unite(int u, int v, int t) {
        u = find(u, t), v = find(v, t);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        tim[v] = t;
        sz[u] += sz[v];
        return true;
    }
    inline bool same(int u, int v, int t) {
        return find(u, t) == find(v, t);
    }
};
#line 27 "Test/PartiallyPersistentUF.test.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    set<P> st;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        st.insert(P(a, b));
    }
    V<int> c(q), d(q);
    for (int i = 0; i < q; i++) {
        cin >> c[i] >> d[i];
        --c[i];
        --d[i];
        st.erase(P(c[i], d[i]));
    }
    UnionFind uf(n);
    for (auto &e : st) {
        uf.unite(e.first, e.second, 0);
    }
    for (int i = q - 1; i >= 0; i--) {
        uf.unite(c[i], d[i], q - i);
    }
    for (int i = 1; i < n; i++) {
        if (uf.same(0, i, 0)) {
            cout << -1 << '\n';
            continue;
        }
        if (!uf.same(0, i, q)) {
            cout << 0 << '\n';
            continue;
        }
        int ok = 0, ng = q;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (uf.same(0, i, q - mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << ok + 1 << '\n';
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


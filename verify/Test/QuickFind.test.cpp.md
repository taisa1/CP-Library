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


# :heavy_check_mark: Test/QuickFind.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/QuickFind.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 17:59:14+09:00


* see: <a href="https://yukicoder.me/problems/no/416">https://yukicoder.me/problems/no/416</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/QuickFind.cpp.html">DataStructure/QuickFind.cpp</a>


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
#include "../DataStructure/QuickFind.cpp"
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
    V<int> c(q), d(q), res(n);
    for (int i = 0; i < q; i++) {
        cin >> c[i] >> d[i];
        --c[i];
        --d[i];
        st.erase(P(c[i], d[i]));
    }
    QuickFind uf(n);
    for (auto &e : st) {
        uf.unite(e.first, e.second);
    }
    for (auto &e : uf.elements(0)) {
        res[e] = -1;
    }
    for (int i = q - 1; i >= 0; i--) {
        if (uf.same(c[i], d[i])) continue;
        if (!uf.same(c[i], 0)) swap(c[i], d[i]);
        if (uf.same(c[i], 0)) {
            for (auto &e : uf.elements(d[i])) {
                res[e] = i + 1;
            }
        }
        uf.unite(c[i], d[i]);
    }
    for (int i = 1; i < n; i++) {
        cout << res[i] << '\n';
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/QuickFind.test.cpp"
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
#line 1 "DataStructure/QuickFind.cpp"
//@docs Docs/QuickFind.md
struct QuickFind {
    int n;
    vector<vector<int>> vs;
    vector<int> root;
    QuickFind(int n) : n(n), vs(n), root(n) {
        iota(root.begin(), root.end(), 0);
        for (int i = 0; i < n; i++) {
            vs[i].emplace_back(i);
        }
    }
    inline int size(int u) {
        return vs[root[u]].size();
    }
    bool unite(int u, int v) {
        u = root[u], v = root[v];
        if (u == v) return false;
        if (size(u) < size(v)) swap(u, v);
        for (auto &e : vs[v]) {
            vs[u].emplace_back(e);
            root[e] = u;
        }
        return true;
    }
    inline int same(int u, int v) {
        return root[u] == root[v];
    }
    vector<int> &elements(int u) {
        return vs[root[u]];
    }
};
#line 27 "Test/QuickFind.test.cpp"
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
    V<int> c(q), d(q), res(n);
    for (int i = 0; i < q; i++) {
        cin >> c[i] >> d[i];
        --c[i];
        --d[i];
        st.erase(P(c[i], d[i]));
    }
    QuickFind uf(n);
    for (auto &e : st) {
        uf.unite(e.first, e.second);
    }
    for (auto &e : uf.elements(0)) {
        res[e] = -1;
    }
    for (int i = q - 1; i >= 0; i--) {
        if (uf.same(c[i], d[i])) continue;
        if (!uf.same(c[i], 0)) swap(c[i], d[i]);
        if (uf.same(c[i], 0)) {
            for (auto &e : uf.elements(d[i])) {
                res[e] = i + 1;
            }
        }
        uf.unite(c[i], d[i]);
    }
    for (int i = 1; i < n; i++) {
        cout << res[i] << '\n';
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


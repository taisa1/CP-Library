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


# :heavy_check_mark: Test/PotentializedUF.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/PotentializedUF.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 17:59:14+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/PotentializedUnionFind.cpp.html">DataStructure/PotentializedUnionFind.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330"
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
constexpr ll INF = (1LL << 60) - 1LL;
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
#include "../DataStructure/PotentializedUnionFind.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (1) {
        cin >> n >> m;
        if (n == 0) break;
        UnionFind<int> uf(n);
        for (int i = 0; i < m; i++) {
            char c;
            cin >> c;
            if (c == '!') {
                int a, b, w;
                cin >> a >> b >> w;
                --a;
                --b;
                uf.unite(a, b, w);
            } else {
                int a, b;
                cin >> a >> b;
                --a;
                --b;
                if (uf.same(a, b)) {
                    cout << uf.value(b) - uf.value(a) << '\n';
                } else {
                    cout << "UNKNOWN\n";
                }
            }
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/PotentializedUF.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330"
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
constexpr ll INF = (1LL << 60) - 1LL;
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
#line 1 "DataStructure/PotentializedUnionFind.cpp"
//@docs Docs/PotentializedUnionFind.cpp
template <class T>
struct UnionFind {
    vector<int> par, sz;
    vector<T> val;
    UnionFind(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
        val.resize(n);
    }
    inline int find(int x) {
        if (x == par[x]) return x;
        int root = find(par[x]);
        val[x] += val[par[x]];
        return par[x] = root;
    }
    inline T value(int x) { //W(x)-W(root)
        find(x);
        return val[x];
    }
    bool unite(int u, int v, T w) { //W(v)=W(u)+w
        w += value(u), w -= value(v);
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v), w *= -1;
        sz[u] += sz[v];
        par[v] = u;
        val[v] = w;
        return true;
    }
    inline int size(int x) {
        return sz[find(x)];
    }
    inline bool same(int u, int v) {
        return find(u) == find(v);
    }
};
#line 27 "Test/PotentializedUF.test.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (1) {
        cin >> n >> m;
        if (n == 0) break;
        UnionFind<int> uf(n);
        for (int i = 0; i < m; i++) {
            char c;
            cin >> c;
            if (c == '!') {
                int a, b, w;
                cin >> a >> b >> w;
                --a;
                --b;
                uf.unite(a, b, w);
            } else {
                int a, b;
                cin >> a >> b;
                --a;
                --b;
                if (uf.same(a, b)) {
                    cout << uf.value(b) - uf.value(a) << '\n';
                } else {
                    cout << "UNKNOWN\n";
                }
            }
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


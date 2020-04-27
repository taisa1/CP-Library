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


# :heavy_check_mark: Test/LCA.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/LCA.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 12:42:37+09:00


* see: <a href="https://judge.yosupo.jp/problem/lca">https://judge.yosupo.jp/problem/lca</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/LowestCommonAncester.cpp.html">Graph/LowestCommonAncester.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/lca"
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
#include "../Graph/LowestCommonAncester.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    LCA g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g.addedge(p, i);
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << g.lca(u, v) << '\n';
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/LCA.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/lca"
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
#line 1 "Graph/LowestCommonAncester.cpp"
//@docs : Docs/LowestCommonAncester.md
const int LOG = 30;
struct LCA {
    vector<vector<int>> G, par;
    vector<int> dep;
    int n, cnt;
    LCA(const int &n) : n(n), G(n), par(LOG, vector<int>(n, -1)), dep(n), cnt(0) {}
    void addedge(const int &u, const int &v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        cnt++;
        if (cnt == n - 1) {
            build();
        }
    }
    void dfs(int i, int p) {
        par[0][i] = p;
        for (auto &e : G[i]) {
            if (e == p) continue;
            dep[e] = dep[i] + 1;
            dfs(e, i);
        }
    }
    //辺追加後に自動でbuild
    void build() {
        dfs(0, -1);
        for (int i = 1; i < LOG; i++) {
            for (int j = 0; j < n; j++) {
                if (par[i - 1][j] != -1) {
                    par[i][j] = par[i - 1][par[i - 1][j]];
                }
            }
        }
    }
    int lca(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = 19; i >= 0; i--) {
            if (((dep[v] - dep[u]) >> i) & 1) v = par[i][v];
        }
        if (u == v) return u;
        for (int i = 19; i >= 0; i--) {
            if (par[i][u] != par[i][v]) {
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    }
};
#line 27 "Test/LCA.test.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    LCA g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g.addedge(p, i);
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << g.lca(u, v) << '\n';
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


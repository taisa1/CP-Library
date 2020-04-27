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


# :heavy_check_mark: Test/SCC.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/SCC.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 12:42:37+09:00


* see: <a href="https://judge.yosupo.jp/problem/scc">https://judge.yosupo.jp/problem/scc</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/StronglyConnectedComponents.cpp.html">Graph/StronglyConnectedComponents.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/scc"
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
#include "../Graph/StronglyConnectedComponents.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    SCC g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.addedge(a, b);
    }
    int k = g.scc();
    cout << k << '\n';
    for (int i = 0; i < k; i++) {
        cout << g.bl[i].size() << " ";
        printv(g.bl[i]);
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/SCC.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/scc"
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
#line 1 "Graph/StronglyConnectedComponents.cpp"
//@docs Docs/StronglyConnectedComponents.md
struct SCC {
    int n;
    vector<int> ord, vis, cm;
    vector<vector<int>> bl, G, rG;
    SCC(int n) : n(n), bl(n), G(n), rG(n), cm(n), vis(n) {}
    void addedge(int u, int v) {
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    void dfs(int i) {
        vis[i] = 1;
        for (auto &e : G[i]) {
            if (vis[e]) continue;
            dfs(e);
        }
        ord.eb(i);
    }
    void rdfs(int i, int c) {
        vis[i] = 1;
        bl[c].emplace_back(i);
        cm[i] = c;
        for (auto &e : rG[i]) {
            if (vis[e]) continue;
            rdfs(e, c);
        }
    }
    //強連結成分分解し、成分数を返す bl[i]:i番目の成分に属する頂点集合、cm[i]:頂点iの成分
    //成分はトポロジカル順に並ぶ
    int scc() {
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i);
        }
        reverse(ord.begin(), ord.end());
        vis.assign(n, 0);
        int k = 0;
        for (auto &e : ord) {
            if (!vis[e]) {
                bl.emplace_back(vector<int>());
                rdfs(e, k);
                k++;
            }
        }
        return k;
    }
};
#line 28 "Test/SCC.test.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    SCC g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.addedge(a, b);
    }
    int k = g.scc();
    cout << k << '\n';
    for (int i = 0; i < k; i++) {
        cout << g.bl[i].size() << " ";
        printv(g.bl[i]);
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


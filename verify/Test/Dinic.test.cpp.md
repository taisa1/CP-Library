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


# :heavy_check_mark: Test/Dinic.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/Dinic.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 13:33:28+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Flow/Dinic.cpp.html">Flow/Dinic.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"
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
#include "../Flow/Dinic.cpp"
#undef call_from_test
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    Dinic<int> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g.addedge(u, v, c);
    }
    cout << g.maxflow(0, n - 1) << '\n';
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/Dinic.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"
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
#line 1 "Flow/Dinic.cpp"
template <class T>
struct Dinic {
    struct edge {
        int to, rev;
        T cap;
        edge(int to, int rev, T cap) : to(to), rev(rev), cap(cap) {}
    };
    int n;
    vector<vector<edge>> G;
    vector<int> lev, itr;
    Dinic(int n) : n(n), G(n), lev(n), itr(n) {}
    void addedge(int u, int v, T cap) {
        G[u].emplace_back(v, G[v].size(), cap);
        G[v].emplace_back(u, (int)G[u].size() - 1, 0);
    }
    void bfs(int s) {
        lev.assign(n, -1);
        queue<int> q;
        lev[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto &e : G[i]) {
                if (lev[e.to] == -1 && e.cap > 0) {
                    lev[e.to] = lev[i] + 1;
                    q.push(e.to);
                }
            }
        }
    }
    T dfs(int i, const int &t, T flow) {
        if (i == t) return flow;
        for (; itr[i] < G[i].size(); itr[i]++) {
            edge &e = G[i][itr[i]];
            if (e.cap == 0 || lev[e.to] <= lev[i]) continue;
            int x = dfs(e.to, t, min(flow, e.cap));
            if (x > 0) {
                e.cap -= x;
                G[e.to][e.rev].cap += x;
                return x;
            }
        }
        return 0;
    }
    T maxflow(const int &s, const int &t) {
        T res = 0, inc;
        while (1) {
            bfs(s);
            if (lev[t] == -1) break;
            itr.assign(n, 0);
            while (1) {
                inc = dfs(s, t, INF);
                if (inc == 0) break;
                res += inc;
            }
        }
        return res;
    }
};
#line 27 "Test/Dinic.test.cpp"
#undef call_from_test
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    Dinic<int> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g.addedge(u, v, c);
    }
    cout << g.maxflow(0, n - 1) << '\n';
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


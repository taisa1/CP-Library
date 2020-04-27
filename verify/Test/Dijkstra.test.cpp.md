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


# :heavy_check_mark: Test/Dijkstra.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/Dijkstra.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 12:42:37+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/Dijkstra.cpp.html">Graph/Dijkstra.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"
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
#include "../Graph/Dijkstra.cpp"
#undef call_from_test
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m, s;
    cin >> n >> m >> s;
    Dijkstra<int> g(n);
    for (int i = 0; i < m; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        g.addedge(s, t, d);
    }
    V<int> d = g.dijkstra(s);
    for (int i = 0; i < n; i++) {
        if (d[i] == INF) {
            cout << "INF\n";
        } else {
            cout << d[i] << '\n';
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/Dijkstra.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"
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
#line 1 "Graph/Dijkstra.cpp"
//@docs Docs/Dijkstra.md
template <class T>
struct Dijkstra {
    int n;
    vector<vector<pair<T, int>>> G;
    Dijkstra(int n) : n(n), G(n) {}
    void addedge(const int &u, const int &v, const T &c) { G[u].emplace_back(v, c); }
    vector<T> dijkstra(const int &st) {
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
        vector<T> d(n, INF);
        d[st] = 0;
        q.emplace(0, st);
        while (!q.empty()) {
            int v = q.top().second;
            T dd = q.top().first;
            q.pop();
            if (d[v] < dd) continue;
            for (auto &e : G[v]) {
                if (d[e.first] > d[v] + e.second) {
                    d[e.first] = d[v] + e.second;
                    q.emplace(d[e.first], e.first);
                }
            }
        }
        return d;
    }
};
#line 27 "Test/Dijkstra.test.cpp"
#undef call_from_test
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m, s;
    cin >> n >> m >> s;
    Dijkstra<int> g(n);
    for (int i = 0; i < m; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        g.addedge(s, t, d);
    }
    V<int> d = g.dijkstra(s);
    for (int i = 0; i < n; i++) {
        if (d[i] == INF) {
            cout << "INF\n";
        } else {
            cout << d[i] << '\n';
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


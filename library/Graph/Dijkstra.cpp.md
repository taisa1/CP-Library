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


# :warning: Graph/Dijkstra.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/Dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-15 13:25:24+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct Dijkstra {
    int n;
    vector<vector<P>> G;
    Dijkstra(int n) : n(n), G(n) {}
    void addedge(int u, int v, ll c) { G[u].emplace_back(v, c); }
    vector<ll> dijkstra(int st) {
        priority_queue<P, vector<P>, greater<P>> q;
        vector<ll> d(n, INF);
        d[st] = 0;
        q.emplace(0, st);
        while (!q.empty()) {
            int v = q.top().second;
            q.pop();
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/Dijkstra.cpp"
struct Dijkstra {
    int n;
    vector<vector<P>> G;
    Dijkstra(int n) : n(n), G(n) {}
    void addedge(int u, int v, ll c) { G[u].emplace_back(v, c); }
    vector<ll> dijkstra(int st) {
        priority_queue<P, vector<P>, greater<P>> q;
        vector<ll> d(n, INF);
        d[st] = 0;
        q.emplace(0, st);
        while (!q.empty()) {
            int v = q.top().second;
            q.pop();
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


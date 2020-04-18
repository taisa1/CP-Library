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


# :warning: Flow/FordFulkerson.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f1a76f66cca677c6e628d9ca58a6c8fc">Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/Flow/FordFulkerson.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-12 12:04:28+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T>
struct FordFulkerson {
    struct edge {
        int to;
        int rev;
        T cap;
    };
    vector<vector<edge>> G;
    vector<int> vis;
    FordFulkerson(int n) : G(n), vis(n) {}
    inline void addedge(int u, int v, T c) {
        G[u].emplace_back(edge{v, (int)G[v].size(), c});
        G[v].emplace_back(edge{u, (int)G[u].size() - 1, 0});
    }
    T dfs(int i, const int &t, T flow) {
        if (i == t) return flow;
        vis[i] = 1;
        for (auto &e : G[i]) {
            if (e.cap == 0 || vis[e.to]) continue;
            T x = dfs(e.to, t, min(flow, e.cap));
            if (x > 0) {
                e.cap -= x;
                G[e.to][e.rev].cap += x;
                return x;
            }
        }
        return 0;
    }
    T maxflow(const int &s, const int &t) {
        T res = 0;
        while (1) {
            fill(all(vis), 0);
            T inc = dfs(s, t, INF);
            if (inc == 0) break;
            res += inc;
        }
        return res;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Flow/FordFulkerson.cpp"
template <class T>
struct FordFulkerson {
    struct edge {
        int to;
        int rev;
        T cap;
    };
    vector<vector<edge>> G;
    vector<int> vis;
    FordFulkerson(int n) : G(n), vis(n) {}
    inline void addedge(int u, int v, T c) {
        G[u].emplace_back(edge{v, (int)G[v].size(), c});
        G[v].emplace_back(edge{u, (int)G[u].size() - 1, 0});
    }
    T dfs(int i, const int &t, T flow) {
        if (i == t) return flow;
        vis[i] = 1;
        for (auto &e : G[i]) {
            if (e.cap == 0 || vis[e.to]) continue;
            T x = dfs(e.to, t, min(flow, e.cap));
            if (x > 0) {
                e.cap -= x;
                G[e.to][e.rev].cap += x;
                return x;
            }
        }
        return 0;
    }
    T maxflow(const int &s, const int &t) {
        T res = 0;
        while (1) {
            fill(all(vis), 0);
            T inc = dfs(s, t, INF);
            if (inc == 0) break;
            res += inc;
        }
        return res;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


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


# :warning: Flow/Dinic.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f1a76f66cca677c6e628d9ca58a6c8fc">Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/Flow/Dinic.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-15 13:25:24+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
    void add_edge(int u, int v, T cap) {
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
    void add_edge(int u, int v, T cap) {
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


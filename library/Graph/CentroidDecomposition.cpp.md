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


# :warning: Graph/CentroidDecomposition.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/CentroidDecomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 01:10:06+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct CentroidD {
    vector<vector<int>> G, be;
    vector<int> sz, vis;
    CentroidD(int n) : G(n), be(n), sz(n), vis(n) {}
    void addedge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void szd(int i, int p) {
        sz[i] = 1;
        for (auto &e : G[i]) {
            if (e == p || vis[e]) continue;
            szd(e, i);
            sz[i] += sz[e];
        }
    }
    int findc(int i, int p, int lim) {
        for (auto &e : G[i]) {
            if (e == p || vis[e]) continue;
            if (sz[e] > lim) {
                return findc(e, i, lim);
            }
        }
        return i;
    }
    void bel(int i, int p, int c) {
        be[i].eb(c);
        for (auto &e : G[i]) {
            if (e == p || vis[e]) continue;
            bel(e, i, c);
        }
    }
    void build(int rt) {
        szd(rt, -1);
        int c = findc(rt, -1, sz[rt] / 2);
        bel(rt, -1, c);
        vis[c] = 1;
        for (auto &e : G[c]) {
            if (vis[e]) continue;
            build(e);
        }
        vis[c] = 0;
    }
    void calc(int rt) {
        szd(rt, -1);
        int c = findc(rt, -1, sz[rt] / 2);
        //ここで部分木について処理
        vis[c] = 1;
        for (auto &e : G[c]) {
            if (vis[e]) continue;
            calc(e);
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/CentroidDecomposition.cpp"
struct CentroidD {
    vector<vector<int>> G, be;
    vector<int> sz, vis;
    CentroidD(int n) : G(n), be(n), sz(n), vis(n) {}
    void addedge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void szd(int i, int p) {
        sz[i] = 1;
        for (auto &e : G[i]) {
            if (e == p || vis[e]) continue;
            szd(e, i);
            sz[i] += sz[e];
        }
    }
    int findc(int i, int p, int lim) {
        for (auto &e : G[i]) {
            if (e == p || vis[e]) continue;
            if (sz[e] > lim) {
                return findc(e, i, lim);
            }
        }
        return i;
    }
    void bel(int i, int p, int c) {
        be[i].eb(c);
        for (auto &e : G[i]) {
            if (e == p || vis[e]) continue;
            bel(e, i, c);
        }
    }
    void build(int rt) {
        szd(rt, -1);
        int c = findc(rt, -1, sz[rt] / 2);
        bel(rt, -1, c);
        vis[c] = 1;
        for (auto &e : G[c]) {
            if (vis[e]) continue;
            build(e);
        }
        vis[c] = 0;
    }
    void calc(int rt) {
        szd(rt, -1);
        int c = findc(rt, -1, sz[rt] / 2);
        //ここで部分木について処理
        vis[c] = 1;
        for (auto &e : G[c]) {
            if (vis[e]) continue;
            calc(e);
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


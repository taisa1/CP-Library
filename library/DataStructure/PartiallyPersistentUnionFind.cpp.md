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


# :warning: DataStructure/PartiallyPersistentUnionFind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/PartiallyPersistentUnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 01:10:06+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct UnionFind {
    int t;
    vector<int> par, siz, tim;
    UnionFind(int n) : par(n), tim(n, INF) {
        siz.assign(n, INF);
        iota(par.begin(), par.end(), 0);
        t = -1;
    }
    int find(int x, int ti) {
        while (x != par[x] && ti >= tim[par[x]]) {
            x = par[x];
        }
        return x;
    }
    bool unite(int u, int v) {
        u = find(u, t), v = find(v, t);
        t++;
        if (u == v) return false;
        if (siz[u] < siz[v]) swap(u, v);
        par[v] = u;
        siz[u] += siz[v];
        tim[v] = t;
        return true;
    }
    //ti回目(0-indexed)のunite後の状態を調べる
    bool same(int u, int v, int ti) { return find(u, ti) == find(v, ti); }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/PartiallyPersistentUnionFind.cpp"
struct UnionFind {
    int t;
    vector<int> par, siz, tim;
    UnionFind(int n) : par(n), tim(n, INF) {
        siz.assign(n, INF);
        iota(par.begin(), par.end(), 0);
        t = -1;
    }
    int find(int x, int ti) {
        while (x != par[x] && ti >= tim[par[x]]) {
            x = par[x];
        }
        return x;
    }
    bool unite(int u, int v) {
        u = find(u, t), v = find(v, t);
        t++;
        if (u == v) return false;
        if (siz[u] < siz[v]) swap(u, v);
        par[v] = u;
        siz[u] += siz[v];
        tim[v] = t;
        return true;
    }
    //ti回目(0-indexed)のunite後の状態を調べる
    bool same(int u, int v, int ti) { return find(u, ti) == find(v, ti); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


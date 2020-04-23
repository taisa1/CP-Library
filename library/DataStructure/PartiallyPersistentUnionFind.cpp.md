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


# :x: DataStructure/PartiallyPersistentUnionFind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/PartiallyPersistentUnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 12:44:51+09:00




## Verified with

* :x: <a href="../../verify/Test/PartiallyPersistentUF.test.cpp.html">Test/PartiallyPersistentUF.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct UnionFind {
    vector<int> par, sz, tim;
    UnionFind(int n) : par(n), sz(n, 1), tim(n, -1) {
        iota(par.begin(), par.end(), 0);
    }
    //時刻tのunionの後のrootを求める
    inline int find(int x, int t) {
        while (par[x] != x && tim[x] <= t) x = par[x];
        return x;
    }
    //与えられるtは広義単調増加
    bool unite(int u, int v, int t) {
        u = find(u, t), v = find(v, t);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        tim[v] = t;
        return true;
    }
    inline bool same(int u, int v, int t) {
        return find(u, t) == find(v, t);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/PartiallyPersistentUnionFind.cpp"
struct UnionFind {
    vector<int> par, sz, tim;
    UnionFind(int n) : par(n), sz(n, 1), tim(n, -1) {
        iota(par.begin(), par.end(), 0);
    }
    //時刻tのunionの後のrootを求める
    inline int find(int x, int t) {
        while (par[x] != x && tim[x] <= t) x = par[x];
        return x;
    }
    //与えられるtは広義単調増加
    bool unite(int u, int v, int t) {
        u = find(u, t), v = find(v, t);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        tim[v] = t;
        return true;
    }
    inline bool same(int u, int v, int t) {
        return find(u, t) == find(v, t);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


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


# :heavy_check_mark: DataStructure/UnionFind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/UnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:04:18+09:00




## Description
素集合を管理する。  
find(x) : x の属する集合の root を返す。 O(α(N))  
unite(u,v) : u,v それぞれが属する集合を併合する。 O(α(N))  
size(x) : x の属する集合のサイズを返す。 O(1)  
same(u,v) : u,v が同じ集合に属するか判定する。 O(α(N))  


## Verified with

* :heavy_check_mark: <a href="../../verify/Test/UnionFind.test.cpp.html">Test/UnionFind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//@docs Docs/UnionFind.md
struct UnionFind {
    vector<int> par, sz;
    UnionFind(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    inline int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
    inline int size(int x) {
        return sz[find(x)];
    }
    inline bool same(int u, int v) {
        return find(u) == find(v);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/UnionFind.cpp"
//@docs Docs/UnionFind.md
struct UnionFind {
    vector<int> par, sz;
    UnionFind(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    inline int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
    inline int size(int x) {
        return sz[find(x)];
    }
    inline bool same(int u, int v) {
        return find(u) == find(v);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


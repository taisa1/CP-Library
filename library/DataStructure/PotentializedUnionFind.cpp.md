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


# :x: DataStructure/PotentializedUnionFind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/PotentializedUnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 13:26:56+09:00




## Verified with

* :x: <a href="../../verify/Test/PotentializedUF.test.cpp.html">Test/PotentializedUF.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T>
struct UnionFind {
    vector<int> par, sz;
    vector<T> val;
    UnionFind(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
        val.resize(n);
    }
    inline int find(int x) {
        if (x == par[x]) return x;
        val[x] += val[par[x]];
        return par[x] = find(par[x]);
    }
    inline T value(int x) { //W(x)-W(root)
        find(x);
        return val[x];
    }
    bool unite(int u, int v, T w) { //W(v)=W(u)+w
        w += value(u), w -= value(v);
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v), w *= -1;
        sz[u] += sz[v];
        par[v] = u;
        val[v] = w;
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
#line 1 "DataStructure/PotentializedUnionFind.cpp"
template <class T>
struct UnionFind {
    vector<int> par, sz;
    vector<T> val;
    UnionFind(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
        val.resize(n);
    }
    inline int find(int x) {
        if (x == par[x]) return x;
        val[x] += val[par[x]];
        return par[x] = find(par[x]);
    }
    inline T value(int x) { //W(x)-W(root)
        find(x);
        return val[x];
    }
    bool unite(int u, int v, T w) { //W(v)=W(u)+w
        w += value(u), w -= value(v);
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v), w *= -1;
        sz[u] += sz[v];
        par[v] = u;
        val[v] = w;
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


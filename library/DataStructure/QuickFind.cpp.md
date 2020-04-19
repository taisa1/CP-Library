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


# :heavy_check_mark: DataStructure/QuickFind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/QuickFind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-19 16:34:59+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/QuickFind.test.cpp.html">Test/QuickFind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct QuickFind {
    int n;
    vector<vector<int>> vs;
    vector<int> root;
    QuickFind(int n) : n(n), vs(n), root(n) {
        iota(root.begin(), root.end(), 0);
        for (int i = 0; i < n; i++) {
            vs[i].emplace_back(i);
        }
    }
    inline int size(int u) {
        return vs[root[u]].size();
    }
    bool unite(int u, int v) {
        u = root[u], v = root[v];
        if (u == v) return false;
        if (size(u) < size(v)) swap(u, v);
        for (auto &e : vs[v]) {
            vs[u].emplace_back(e);
            root[e] = u;
        }
        return true;
    }
    inline int same(int u, int v) {
        return root[u] == root[v];
    }
    vector<int> &elements(int u) {
        return vs[root[u]];
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/QuickFind.cpp"
struct QuickFind {
    int n;
    vector<vector<int>> vs;
    vector<int> root;
    QuickFind(int n) : n(n), vs(n), root(n) {
        iota(root.begin(), root.end(), 0);
        for (int i = 0; i < n; i++) {
            vs[i].emplace_back(i);
        }
    }
    inline int size(int u) {
        return vs[root[u]].size();
    }
    bool unite(int u, int v) {
        u = root[u], v = root[v];
        if (u == v) return false;
        if (size(u) < size(v)) swap(u, v);
        for (auto &e : vs[v]) {
            vs[u].emplace_back(e);
            root[e] = u;
        }
        return true;
    }
    inline int same(int u, int v) {
        return root[u] == root[v];
    }
    vector<int> &elements(int u) {
        return vs[root[u]];
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


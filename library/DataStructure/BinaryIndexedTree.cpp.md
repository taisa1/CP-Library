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


# :x: DataStructure/BinaryIndexedTree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/BinaryIndexedTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 10:49:59+09:00




## Verified with

* :x: <a href="../../verify/Tests/BinaryIndexedTree.test.cpp.html">Tests/BinaryIndexedTree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//Point Add Range Sum
template <typename T>
struct BinaryIndexedTree {
    vector<T> node;
    int n;
    BinaryIndexedTree(int n) : n(n) { node.assign(++n, 0); }
    void add(int k, T x) {
        for (++k; k < n; k += k & -k) {
            node[k] += x;
        }
    }
    T get(int k) {
        T res = 0;
        for (++k; k > 0; k -= k & -k) {
            res += node[k];
        }
        return res;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/BinaryIndexedTree.cpp"
//Point Add Range Sum
template <typename T>
struct BinaryIndexedTree {
    vector<T> node;
    int n;
    BinaryIndexedTree(int n) : n(n) { node.assign(++n, 0); }
    void add(int k, T x) {
        for (++k; k < n; k += k & -k) {
            node[k] += x;
        }
    }
    T get(int k) {
        T res = 0;
        for (++k; k > 0; k -= k & -k) {
            res += node[k];
        }
        return res;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

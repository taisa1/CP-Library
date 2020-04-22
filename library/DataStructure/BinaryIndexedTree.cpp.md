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


# :question: DataStructure/BinaryIndexedTree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/BinaryIndexedTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 11:20:57+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/BinaryIndexedTree.test.cpp.html">Test/BinaryIndexedTree.test.cpp</a>
* :x: <a href="../../verify/Test/HLDpath.test.cpp.html">Test/HLDpath.test.cpp</a>
* :x: <a href="../../verify/Test/HLDsubtree.test.cpp.html">Test/HLDsubtree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//Point Add Range Sum
template <class T>
struct BinaryIndexedTree {
    int n;
    vector<T> dat;
    BinaryIndexedTree(int n_) : n(n_ + 1), dat(n_ + 1) {}
    void add(int k, T x) {
        for (++k; k < n; k += k & -k) dat[k] += x;
    }
    T get(int k) {
        T res = 0;
        for (++k; k > 0; k -= k & -k) res += dat[k];
        return res;
    }
    inline T get(int l, int r) { //0-indexed [l,r)
        return get(r-1) - get(l-1);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/BinaryIndexedTree.cpp"
//Point Add Range Sum
template <class T>
struct BinaryIndexedTree {
    int n;
    vector<T> dat;
    BinaryIndexedTree(int n_) : n(n_ + 1), dat(n_ + 1) {}
    void add(int k, T x) {
        for (++k; k < n; k += k & -k) dat[k] += x;
    }
    T get(int k) {
        T res = 0;
        for (++k; k > 0; k -= k & -k) res += dat[k];
        return res;
    }
    inline T get(int l, int r) { //0-indexed [l,r)
        return get(r-1) - get(l-1);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


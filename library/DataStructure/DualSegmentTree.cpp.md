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


# :heavy_check_mark: DataStructure/DualSegmentTree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/DualSegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-25 22:15:31+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/DualSegmentTree.test.cpp.html">Test/DualSegmentTree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//Range Update Point Get
template <class T>
struct Segtree {
    vector<T> dat;
    int n;
    T e;
    Segtree(int n_) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, T::id());
    }
    void upd(const int &a, const int &b, const T &x, int k, int l, int r) {
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            dat[k].g(x);
            return;
        }
        upd(a, b, x, k << 1, l, (l + r) >> 1);
        upd(a, b, x, k << 1 | 1, (l + r) >> 1, r);
    }
    inline void upd(const int &a, const int &b, const T &x) {
        if (a >= b) {
            return;
        }
        upd(a, b, x, 1, 0, n);
    }
    T get(int k) {
        k += n;
        T res = dat[k];
        k >>= 1;
        while (k > 0) {
            res = T::f(res, dat[k]);
            k >>= 1;
        }
        return res;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/DualSegmentTree.cpp"
//Range Update Point Get
template <class T>
struct Segtree {
    vector<T> dat;
    int n;
    T e;
    Segtree(int n_) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, T::id());
    }
    void upd(const int &a, const int &b, const T &x, int k, int l, int r) {
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            dat[k].g(x);
            return;
        }
        upd(a, b, x, k << 1, l, (l + r) >> 1);
        upd(a, b, x, k << 1 | 1, (l + r) >> 1, r);
    }
    inline void upd(const int &a, const int &b, const T &x) {
        if (a >= b) {
            return;
        }
        upd(a, b, x, 1, 0, n);
    }
    T get(int k) {
        k += n;
        T res = dat[k];
        k >>= 1;
        while (k > 0) {
            res = T::f(res, dat[k]);
            k >>= 1;
        }
        return res;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


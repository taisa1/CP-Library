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


# :heavy_check_mark: DataStructure/SparseTable.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SparseTable.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 12:06:47+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/SparseTable.test.cpp.html">Test/SparseTable.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T>
struct SparseTable {
    int n;
    vector<vector<T>> dat;
    vector<int> lg, p;
    SparseTable(int n, T e) : n(n), lg(n + 1), p(30) {
        dat.resize(30, vector<T>(n, e));
        for (int i = 1; i <= n; i++) {
            lg[i] = 31 - __builtin_clz(i);
        }
        p[0] = 1;
        for (int i = 1; i < 30; i++) {
            p[i] = p[i - 1] * 2;
        }
    }
    void build(const vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            dat[0][i] = a[i];
        }
        for (int i = 1; i <= lg[n]; i++) {
            for (int j = 0; j < n; j++) {
                if (j + p[i - 1] >= n) continue;
                dat[i][j] = min(dat[i - 1][j], dat[i - 1][j + p[i - 1]]);
            }
        }
    }
    T get(int l, int r) { //0-indexed [l,r)
        return min(dat[lg[r - l]][l], dat[lg[r - l]][r - p[lg[r - l]]]);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SparseTable.cpp"
template <class T>
struct SparseTable {
    int n;
    vector<vector<T>> dat;
    vector<int> lg, p;
    SparseTable(int n, T e) : n(n), lg(n + 1), p(30) {
        dat.resize(30, vector<T>(n, e));
        for (int i = 1; i <= n; i++) {
            lg[i] = 31 - __builtin_clz(i);
        }
        p[0] = 1;
        for (int i = 1; i < 30; i++) {
            p[i] = p[i - 1] * 2;
        }
    }
    void build(const vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            dat[0][i] = a[i];
        }
        for (int i = 1; i <= lg[n]; i++) {
            for (int j = 0; j < n; j++) {
                if (j + p[i - 1] >= n) continue;
                dat[i][j] = min(dat[i - 1][j], dat[i - 1][j + p[i - 1]]);
            }
        }
    }
    T get(int l, int r) { //0-indexed [l,r)
        return min(dat[lg[r - l]][l], dat[lg[r - l]][r - p[lg[r - l]]]);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


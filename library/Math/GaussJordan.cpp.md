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


# :warning: Math/GaussJordan.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/GaussJordan.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 01:10:06+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
const int maxH = 100030, maxW = 310;
struct BitMatrix {
    bitset<maxW> a[maxH];
    int n, m;
    BitMatrix(int n_, int m_) : n(n_), m(m_) {}
    inline bitset<maxW> &operator[](int i) { return a[i]; }
};

//bitmatrix を掃き出し、rankを返す
int GaussJordan(BitMatrix &a, bool extended) {
    int rank = 0;
    for (int j = 0; j < a.m; j++) {
        if (extended && j + 1 == a.m) break;
        int piv = -1;
        for (int i = rank; i < a.n; i++) {
            if (a[i][j]) {
                piv = i;
                break;
            }
        }
        if (piv == -1) continue;
        swap(a[rank], a[piv]);
        piv = rank;
        for (int i = 0; i < a.n; i++) {
            if (i == piv) continue;
            if (a[i][j]) {
                a[i] ^= a[piv];
            }
        }
        rank++;
    }
    return rank;
}
//ax=b なるベクトルxを求め、自由度を返す O(HW^2) a:H*W b:H*1 x:W*1
int LinearEquation(BitMatrix a, vector<int> b, vector<int> &x) {
    BitMatrix na(a.n, a.m + 1);
    for (int i = 0; i < a.n; i++) {
        na[i] = a[i];
        na[i][a.m] = b[i];
    }
    int rank = GaussJordan(na, true);
    for (int i = rank; i < a.n; i++) {
        if (na[i][a.m]) return -1;
    }
    x.assign(a.m, 0);
    for (int i = 0; i < rank; i++) {
        x[i] = na[i][a.m];
    }
    return a.m - rank;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/GaussJordan.cpp"
const int maxH = 100030, maxW = 310;
struct BitMatrix {
    bitset<maxW> a[maxH];
    int n, m;
    BitMatrix(int n_, int m_) : n(n_), m(m_) {}
    inline bitset<maxW> &operator[](int i) { return a[i]; }
};

//bitmatrix を掃き出し、rankを返す
int GaussJordan(BitMatrix &a, bool extended) {
    int rank = 0;
    for (int j = 0; j < a.m; j++) {
        if (extended && j + 1 == a.m) break;
        int piv = -1;
        for (int i = rank; i < a.n; i++) {
            if (a[i][j]) {
                piv = i;
                break;
            }
        }
        if (piv == -1) continue;
        swap(a[rank], a[piv]);
        piv = rank;
        for (int i = 0; i < a.n; i++) {
            if (i == piv) continue;
            if (a[i][j]) {
                a[i] ^= a[piv];
            }
        }
        rank++;
    }
    return rank;
}
//ax=b なるベクトルxを求め、自由度を返す O(HW^2) a:H*W b:H*1 x:W*1
int LinearEquation(BitMatrix a, vector<int> b, vector<int> &x) {
    BitMatrix na(a.n, a.m + 1);
    for (int i = 0; i < a.n; i++) {
        na[i] = a[i];
        na[i][a.m] = b[i];
    }
    int rank = GaussJordan(na, true);
    for (int i = rank; i < a.n; i++) {
        if (na[i][a.m]) return -1;
    }
    x.assign(a.m, 0);
    for (int i = 0; i < rank; i++) {
        x[i] = na[i][a.m];
    }
    return a.m - rank;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


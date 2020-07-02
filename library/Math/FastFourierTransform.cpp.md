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


# :warning: Math/FastFourierTransform.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/FastFourierTransform.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-02 17:57:15+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct FFT {
    using D = double;
    using C = complex<D>;
    static void dft(vector<C> &v, int inv) {
        int sz = v.size();
        if (sz == 1) return;
        int hf = sz / 2;
        vector<C> va(hf), vb(hf);
        for (int i = 0; i < hf; i++) {
            va[i] = v[i << 1];
            vb[i] = v[i << 1 | 1];
        }
        dft(va, inv);
        dft(vb, inv);
        C w = polar(1.0, 2.0 * acos(-1.0) * inv / sz), now = 1;
        for (int i = 0; i < sz; i++) {
            v[i] = va[i % hf] + now * vb[i % hf];
            now *= w;
        }
    }
    template <class T>
    static vector<T> convolution(vector<T> a, vector<T> b) {
        int na = a.size(), nb = b.size();
        int sz = 1, rn = na + nb - 1;
        while (sz < rn) sz <<= 1;
        vector<C> A(sz), B(sz);
        for (int i = 0; i < na; i++) A[i] = a[i];
        for (int i = 0; i < nb; i++) B[i] = b[i];
        dft(A, 1);
        dft(B, 1);
        for (int i = 0; i < sz; i++) A[i] *= B[i];
        dft(A, -1);
        a.resize(rn);
        for (int i = 0; i < rn; i++) a[i] = A[i].real() / sz;
        return a;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/FastFourierTransform.cpp"
struct FFT {
    using D = double;
    using C = complex<D>;
    static void dft(vector<C> &v, int inv) {
        int sz = v.size();
        if (sz == 1) return;
        int hf = sz / 2;
        vector<C> va(hf), vb(hf);
        for (int i = 0; i < hf; i++) {
            va[i] = v[i << 1];
            vb[i] = v[i << 1 | 1];
        }
        dft(va, inv);
        dft(vb, inv);
        C w = polar(1.0, 2.0 * acos(-1.0) * inv / sz), now = 1;
        for (int i = 0; i < sz; i++) {
            v[i] = va[i % hf] + now * vb[i % hf];
            now *= w;
        }
    }
    template <class T>
    static vector<T> convolution(vector<T> a, vector<T> b) {
        int na = a.size(), nb = b.size();
        int sz = 1, rn = na + nb - 1;
        while (sz < rn) sz <<= 1;
        vector<C> A(sz), B(sz);
        for (int i = 0; i < na; i++) A[i] = a[i];
        for (int i = 0; i < nb; i++) B[i] = b[i];
        dft(A, 1);
        dft(B, 1);
        for (int i = 0; i < sz; i++) A[i] *= B[i];
        dft(A, -1);
        a.resize(rn);
        for (int i = 0; i < rn; i++) a[i] = A[i].real() / sz;
        return a;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


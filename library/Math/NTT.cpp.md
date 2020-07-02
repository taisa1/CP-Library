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


# :warning: Math/NTT.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/NTT.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-02 23:01:01+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
constexpr mint proot = 3;
struct NTT {
    static void dft(vector<mint> &v, const int &inv) {
        int sz = v.size();
        if (sz == 1) return;
        int hf = sz / 2;
        vector<mint> va(hf), vb(hf);
        for (int i = 0; i < hf; i++) {
            va[i] = v[i << 1];
            vb[i] = v[i << 1 | 1];
        }
        dft(va, inv);
        dft(vb, inv);
        mint w = (inv > 0 ? proot : mint(1) / proot) ^ (mint(MOD - 1) / mint(sz)).a, now = 1;
        for (int i = 0; i < sz; i++) {
            v[i] = va[i % hf] + now * vb[i % hf];
            now *= w;
        }
    }
    static vector<mint> convolution(const vector<mint> &a, const vector<mint> &b) {
        int na = a.size(), nb = b.size();
        int sz = 1, rn = na + nb - 1;
        while (sz < rn) sz <<= 1;
        vector<mint> A(sz), B(sz);
        for (int i = 0; i < na; i++) A[i] = a[i];
        for (int i = 0; i < nb; i++) B[i] = b[i];
        dft(A, 1);
        dft(B, 1);
        for (int i = 0; i < sz; i++) A[i] *= B[i];
        dft(A, -1);
        vector<mint> res(rn);
        for (int i = 0; i < rn; i++) res[i] = A[i] / mint(sz);
        return res;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/NTT.cpp"
constexpr mint proot = 3;
struct NTT {
    static void dft(vector<mint> &v, const int &inv) {
        int sz = v.size();
        if (sz == 1) return;
        int hf = sz / 2;
        vector<mint> va(hf), vb(hf);
        for (int i = 0; i < hf; i++) {
            va[i] = v[i << 1];
            vb[i] = v[i << 1 | 1];
        }
        dft(va, inv);
        dft(vb, inv);
        mint w = (inv > 0 ? proot : mint(1) / proot) ^ (mint(MOD - 1) / mint(sz)).a, now = 1;
        for (int i = 0; i < sz; i++) {
            v[i] = va[i % hf] + now * vb[i % hf];
            now *= w;
        }
    }
    static vector<mint> convolution(const vector<mint> &a, const vector<mint> &b) {
        int na = a.size(), nb = b.size();
        int sz = 1, rn = na + nb - 1;
        while (sz < rn) sz <<= 1;
        vector<mint> A(sz), B(sz);
        for (int i = 0; i < na; i++) A[i] = a[i];
        for (int i = 0; i < nb; i++) B[i] = b[i];
        dft(A, 1);
        dft(B, 1);
        for (int i = 0; i < sz; i++) A[i] *= B[i];
        dft(A, -1);
        vector<mint> res(rn);
        for (int i = 0; i < rn; i++) res[i] = A[i] / mint(sz);
        return res;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


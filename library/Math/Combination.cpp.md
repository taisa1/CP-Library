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


# :warning: Math/Combination.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Combination.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 12:56:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
ector<mint> f, fi;
void comb(int n) {
    f.resize(n + 1);
    fi.resize(n + 1);
    f[0] = 1;
    for (ll i = 1; i <= n; i++) {
        f[i] = f[i - 1] * mint(i);
    }
    fi[n] = mint(1) / f[n];
    for (ll i = n - 1; i >= 0; i--) {
        fi[i] = fi[i + 1] * mint(i + 1LL);
    }
}
mint ncr(ll n, ll r) {
    if (n < r) {
        return mint(0);
    }
    if (r == 0) {
        return mint(1);
    }
    return f[n] * fi[n - r] * fi[r];
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/Combination.cpp"
ector<mint> f, fi;
void comb(int n) {
    f.resize(n + 1);
    fi.resize(n + 1);
    f[0] = 1;
    for (ll i = 1; i <= n; i++) {
        f[i] = f[i - 1] * mint(i);
    }
    fi[n] = mint(1) / f[n];
    for (ll i = n - 1; i >= 0; i--) {
        fi[i] = fi[i + 1] * mint(i + 1LL);
    }
}
mint ncr(ll n, ll r) {
    if (n < r) {
        return mint(0);
    }
    if (r == 0) {
        return mint(1);
    }
    return f[n] * fi[n - r] * fi[r];
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


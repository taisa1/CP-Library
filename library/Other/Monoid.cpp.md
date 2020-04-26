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


# :warning: Other/Monoid.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6311ae17c1ee52b36e68aaf4ad066387">Other</a>
* <a href="{{ site.github.repository_url }}/blob/master/Other/Monoid.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 12:37:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//segtree(example:RMQ)
struct T {
    ll x;
    T() {}
    T(ll x) : x(x) {}
    inline static T id() {
        return 1LL << 60;
    }
    inline static T f(const T &x, const T &y) {
        return T(min(x.x, y.x));
    }
    inline static T g(const T &a, const T &b) {
        return b;
    }
};
//lazy segtree(example:RAQ+RMQ)
struct E {
    ll x;
    E() {}
    E(ll x) : x(x) {}
    inline static E id() {
        return E(0);
    }
    inline static E f(const E &x, const E &y) {
        return E(x + y);
    }
};
struct T {
    ll x;
    T() {}
    T(ll x) : x(x) {}
    inline static T id() {
        return 1LL << 60;
    }
    inline static T f(const T &x, const T &y) {
        return min(x.x, y.x);
    }
    inline static T g(const T &x, const E &y, const ll &len) {
        return x.x + y.x;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Other/Monoid.cpp"
//segtree(example:RMQ)
struct T {
    ll x;
    T() {}
    T(ll x) : x(x) {}
    inline static T id() {
        return 1LL << 60;
    }
    inline static T f(const T &x, const T &y) {
        return T(min(x.x, y.x));
    }
    inline static T g(const T &a, const T &b) {
        return b;
    }
};
//lazy segtree(example:RAQ+RMQ)
struct E {
    ll x;
    E() {}
    E(ll x) : x(x) {}
    inline static E id() {
        return E(0);
    }
    inline static E f(const E &x, const E &y) {
        return E(x + y);
    }
};
struct T {
    ll x;
    T() {}
    T(ll x) : x(x) {}
    inline static T id() {
        return 1LL << 60;
    }
    inline static T f(const T &x, const T &y) {
        return min(x.x, y.x);
    }
    inline static T g(const T &x, const E &y, const ll &len) {
        return x.x + y.x;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


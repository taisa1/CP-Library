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


# :warning: Other/TernarySearch.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6311ae17c1ee52b36e68aaf4ad066387">Other</a>
* <a href="{{ site.github.repository_url }}/blob/master/Other/TernarySearch.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 12:31:28+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
auto calc = [&](auto x) {
    return 0;
};
//整数値での三分探索
auto TernarySearch = [&](auto lb, auto ub) { //[lb,ub]
    using T = decltype(lb);
    T ok = lb - 1, ng = ub;
    while (ng - ok > 1) {
        T mid = (ok + ng) / 2;
        if (calc(mid + 1) - calc(mid) < 0) { //上に凸なら>
            ok = mid;
        } else {
            ng = mid;
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Other/TernarySearch.cpp"
auto calc = [&](auto x) {
    return 0;
};
//整数値での三分探索
auto TernarySearch = [&](auto lb, auto ub) { //[lb,ub]
    using T = decltype(lb);
    T ok = lb - 1, ng = ub;
    while (ng - ok > 1) {
        T mid = (ok + ng) / 2;
        if (calc(mid + 1) - calc(mid) < 0) { //上に凸なら>
            ok = mid;
        } else {
            ng = mid;
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


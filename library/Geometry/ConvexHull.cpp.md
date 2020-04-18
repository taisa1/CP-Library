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


# :warning: Geometry/ConvexHull.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d9c6333623e6357515fcbf17be806273">Geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/Geometry/ConvexHull.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 21:47:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//https://onlinejudge.u-aizu.ac.jp/status/users/TAISA_/submissions/1/CGL_4_A/judge/4344751/C++14
struct ConvexHull : vector<Point> {
    vector<Point> pt;
    ConvexHull(const vector<Point> &pt) : pt(pt) {}
    void build() {
        auto cmp = [](const Point &a, const Point &b) {
            return a.imag() == b.imag() ? a.real() < b.real() : a.imag() < b.imag();
        };
        sort(pt.begin(), pt.end(), cmp);
        for (int i = 0; i < pt.size(); i++) {
            while (size() > 1 && ccw((*this)[size() - 2], back(), pt[i]) <= 0) {
                pop_back();
            }
            emplace_back(pt[i]);
        }
        int lim = size();
        for (int i = (int)pt.size() - 2; i >= 0; i--) {
            while (size() > lim && ccw((*this)[size() - 2], back(), pt[i]) <= 0) {
                pop_back();
            }
            emplace_back(pt[i]);
        }
        pop_back();
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Geometry/ConvexHull.cpp"
//https://onlinejudge.u-aizu.ac.jp/status/users/TAISA_/submissions/1/CGL_4_A/judge/4344751/C++14
struct ConvexHull : vector<Point> {
    vector<Point> pt;
    ConvexHull(const vector<Point> &pt) : pt(pt) {}
    void build() {
        auto cmp = [](const Point &a, const Point &b) {
            return a.imag() == b.imag() ? a.real() < b.real() : a.imag() < b.imag();
        };
        sort(pt.begin(), pt.end(), cmp);
        for (int i = 0; i < pt.size(); i++) {
            while (size() > 1 && ccw((*this)[size() - 2], back(), pt[i]) <= 0) {
                pop_back();
            }
            emplace_back(pt[i]);
        }
        int lim = size();
        for (int i = (int)pt.size() - 2; i >= 0; i--) {
            while (size() > lim && ccw((*this)[size() - 2], back(), pt[i]) <= 0) {
                pop_back();
            }
            emplace_back(pt[i]);
        }
        pop_back();
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


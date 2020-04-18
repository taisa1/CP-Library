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


# :heavy_check_mark: DataStructure/SlidingWindowAggregation.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SlidingWindowAggregation.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 13:33:28+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Test/SWAG.test.cpp.html">Test/SWAG.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T>
struct SWAG {
    SWAG() {}
    stack<pair<T, T>> frontst, backst;
    void push(const T &x) {
        if (backst.empty()) {
            backst.emplace(x, x);
        } else {
            backst.emplace(x, T::f(backst.top().second, x));
        }
    }
    void pop() {
        if (frontst.empty()) {
            while (!backst.empty()) {
                if (frontst.empty()) {
                    frontst.emplace(backst.top().first, backst.top().first);
                } else {
                    frontst.emplace(backst.top().first, T::f(backst.top().first, frontst.top().second));
                }
                backst.pop();
            }
        }
        frontst.pop();
    }
    T fold() {
        if (frontst.empty() && backst.empty()) {
            return T::e;
        }
        if (frontst.empty()) {
            return backst.top().second;
        } else if (backst.empty()) {
            return frontst.top().second;
        }
        return T::f(frontst.top().second, backst.top().second);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SlidingWindowAggregation.cpp"
template <class T>
struct SWAG {
    SWAG() {}
    stack<pair<T, T>> frontst, backst;
    void push(const T &x) {
        if (backst.empty()) {
            backst.emplace(x, x);
        } else {
            backst.emplace(x, T::f(backst.top().second, x));
        }
    }
    void pop() {
        if (frontst.empty()) {
            while (!backst.empty()) {
                if (frontst.empty()) {
                    frontst.emplace(backst.top().first, backst.top().first);
                } else {
                    frontst.emplace(backst.top().first, T::f(backst.top().first, frontst.top().second));
                }
                backst.pop();
            }
        }
        frontst.pop();
    }
    T fold() {
        if (frontst.empty() && backst.empty()) {
            return T::e;
        }
        if (frontst.empty()) {
            return backst.top().second;
        } else if (backst.empty()) {
            return frontst.top().second;
        }
        return T::f(frontst.top().second, backst.top().second);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


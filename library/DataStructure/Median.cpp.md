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


# :warning: DataStructure/Median.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/Median.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 12:42:37+09:00




## Description
集合の中央値を管理する。  
push(x) : 集合に x を追加する。 O(log N)  
get() : 集合の中央値を返す。 O(1)  

## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//@docs Docs/Median.md
template <class T>
struct Median {
    priority_queue<T> smq;
    priority_queue<T, vector<T>, greater<T>> lgq;
    void push(T x) {
        if (smq.empty()) {
            smq.push(x);
            return;
        }
        T t = smq.top();
        if (smq.size() > lgq.size()) {
            if (t <= x) {
                lgq.push(x);
            } else {
                lgq.push(t);
                smq.pop();
                smq.push(x);
            }
        } else {
            if (t >= x) {
                smq.push(x);
            } else {
                lgq.push(x);
                smq.push(lgq.top());
                lgq.pop();
            }
        }
    }
    inline T get() { return smq.top(); }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/Median.cpp"
//@docs Docs/Median.md
template <class T>
struct Median {
    priority_queue<T> smq;
    priority_queue<T, vector<T>, greater<T>> lgq;
    void push(T x) {
        if (smq.empty()) {
            smq.push(x);
            return;
        }
        T t = smq.top();
        if (smq.size() > lgq.size()) {
            if (t <= x) {
                lgq.push(x);
            } else {
                lgq.push(t);
                smq.pop();
                smq.push(x);
            }
        } else {
            if (t >= x) {
                smq.push(x);
            } else {
                lgq.push(x);
                smq.push(lgq.top());
                lgq.pop();
            }
        }
    }
    inline T get() { return smq.top(); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


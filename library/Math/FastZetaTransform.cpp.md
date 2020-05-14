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


# :warning: Math/FastZetaTransform.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/FastZetaTransform.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 15:16:26+09:00




## Description
(集合,値) の組 a に対して高速ゼータ変換を行う。  
up = true のとき : 各集合の値に、その上位集合の和を足す。
up = false のとき : 各集合の値に、その下位集合の和を足す。  

## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//@docs Docs/FastZetaTransform.md
template <class T>
void fzt(vector<T> &a, bool up) {
    int n = a.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                if (up) {
                    a[j] += a[j | i];
                } else {
                    a[j | i] += a[j];
                }
            }
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/FastZetaTransform.cpp"
//@docs Docs/FastZetaTransform.md
template <class T>
void fzt(vector<T> &a, bool up) {
    int n = a.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                if (up) {
                    a[j] += a[j | i];
                } else {
                    a[j | i] += a[j];
                }
            }
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


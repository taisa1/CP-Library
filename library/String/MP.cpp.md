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


# :warning: String/MP.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/MP.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 17:59:14+09:00




## Description
文字列 s について、部分文字列 s[1,i] の prefix と suffix がどこまで一致しているかを示す配列 a を求める。  
計算量は O(|s|) 。  

## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//@docs Docs/MP.md
vector<int> MP(string &s) {
    int j = -1;
    int n = s.length();
    vector<int> a(n + 1);
    a[0] = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) {
            j = a[j];
        }
        j++;
        a[i + 1] = j;
    }
    return a;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "String/MP.cpp"
//@docs Docs/MP.md
vector<int> MP(string &s) {
    int j = -1;
    int n = s.length();
    vector<int> a(n + 1);
    a[0] = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) {
            j = a[j];
        }
        j++;
        a[i + 1] = j;
    }
    return a;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


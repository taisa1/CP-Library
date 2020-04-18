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


# :warning: DataStructure/BinaryTrie.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/BinaryTrie.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 21:47:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class T, int LOG>
struct BinaryTrie {
    struct Node {
        bool a;
        Node *to[2];
        Node(bool a) : a(a) { to[0] = to[1] = nullptr; }
    };
    Node *root;
    BinaryTrie() {
        root = new Node(0);
    }
    void insert(T x) {
        Node *now = root;
        for (int i = LOG - 1; i >= 0; i--) {
            if (now->to[(x >> i) & 1LL] == nullptr) {
                now->to[(x >> i) & 1LL] = new Node((x >> i) & 1LL);
            }
            now = now->to[(x >> i) & 1LL];
        }
    }
    void erase(ll x) {
        Node *now = root;
        for (int i = 0; i < LOG; i++) {
            now = now->to[(x >> (LOG - i)) & 1LL];
            now->cnt--;
        }
    }
    T min_element() {
        Node *now = root;
        for (int i = 0; i < LOG; i++) {
            if (!now->to[0] || now->to[0]->cnt > 0) {
                now = now->to[0];
            } else {
                now = now->to[1];
            }
        }
    }
    T max_element() {
        Node *now = root;
        for (int i = 0; i < LOG; i++) {
            if (!now->to[1] || now->to[1]->cnt > 0) {
                now = now->to[1];
            } else {
                now = now->to[0];
            }
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/BinaryTrie.cpp"
template <class T, int LOG>
struct BinaryTrie {
    struct Node {
        bool a;
        Node *to[2];
        Node(bool a) : a(a) { to[0] = to[1] = nullptr; }
    };
    Node *root;
    BinaryTrie() {
        root = new Node(0);
    }
    void insert(T x) {
        Node *now = root;
        for (int i = LOG - 1; i >= 0; i--) {
            if (now->to[(x >> i) & 1LL] == nullptr) {
                now->to[(x >> i) & 1LL] = new Node((x >> i) & 1LL);
            }
            now = now->to[(x >> i) & 1LL];
        }
    }
    void erase(ll x) {
        Node *now = root;
        for (int i = 0; i < LOG; i++) {
            now = now->to[(x >> (LOG - i)) & 1LL];
            now->cnt--;
        }
    }
    T min_element() {
        Node *now = root;
        for (int i = 0; i < LOG; i++) {
            if (!now->to[0] || now->to[0]->cnt > 0) {
                now = now->to[0];
            } else {
                now = now->to[1];
            }
        }
    }
    T max_element() {
        Node *now = root;
        for (int i = 0; i < LOG; i++) {
            if (!now->to[1] || now->to[1]->cnt > 0) {
                now = now->to[1];
            } else {
                now = now->to[0];
            }
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


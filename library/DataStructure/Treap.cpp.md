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


# :warning: DataStructure/Treap.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/Treap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 21:47:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

struct Xorshift {
    unsigned int get() {
        static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        unsigned int t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }
};
template <class T>
struct Treap {
    Xorshift rnd;
    struct Node {
        T key;
        unsigned int pri;
        int siz;
        Node *l, *r;
        Node(T key, int pri) : key(key), pri(pri), siz(1), l(nullptr), r(nullptr) {}
    } *root = nullptr;
    using Tree = Node *;
    inline T nxt(T x) { return x + 1; }
    inline int size(Tree t) {
        return !t ? 0 : t->siz;
    }
    inline void eval(Tree t) {
        if (!t) return;
        t->siz = 1 + size(t->l) + size(t->r);
    }
    Tree merge(Tree l, Tree r) { //l内のkey < r内のkey
        if (!l || !r) {
            return !l ? r : l;
        }
        if (l->pri > r->pri) {
            l->r = merge(l->r, r);
            eval(l);
            return l;
        } else {
            r->l = merge(l, r->l);
            eval(r);
            return r;
        }
    }
    pair<Tree, Tree> split(Tree t, const T &x) { //key<x,x<=key でsplit
        if (!t) return make_pair(nullptr, nullptr);
        Tree tl, tr;
        tl = tr = nullptr;
        if (t->key < x) {
            tie(tl, tr) = split(t->r, x);
            t->r = tl;
            eval(t);
            tl = t;
        } else {
            tie(tl, tr) = split(t->l, x);
            t->l = tr;
            eval(t);
            tr = t;
        }
        return make_pair(tl, tr);
    }
    void insert(Tree &t, Tree nd) {
        Tree tl, tr;
        tl = tr = nullptr;
        tie(tl, tr) = split(t, nd->key);
        t = merge(merge(tl, nd), tr);
    }
    void erase(Tree &t, const T &x) {
        Tree tl, tm, tr;
        tl = tm = tr = nullptr;
        tie(tl, tm) = split(t, x);
        tie(tm, tr) = split(tm, nxt(x));
        t = merge(tl, tr);
    }
    int count(Tree t, const T &x) {
        if (!t) return 0;
        if (t->key == x) return 1;
        if (x < t->key) {
            return count(t->l, x);
        } else {
            return count(t->r, x);
        }
    }
    int order_of_key(Tree t, const T &x) {
        if (!t) return 0;
        if (x < t->key) {
            return order_of_key(t->l, x);
        } else if (x == t->key) {
            return size(t->l);
        } else {
            return size(t->l) + 1 + order_of_key(t->r, x);
        }
    }
    T find_by_order(Tree t, const int &x) {
        if (x < size(t->l)) {
            return find_by_order(t->l, x);
        } else if (x == size(t->l)) {
            return t->key;
        } else {
            return find_by_order(t->r, x - size(t->l) - 1);
        }
    }
    void get(Tree &t, int l, int r) { //[l,r)
        Tree tl, tm, tr;
        tie(tl, tm) = split(t, l);
        tie(tm, tr) = split(tm, r);
        //tm の情報を取得
        t = merge(tl, merge(tm, tr));
    }
    inline void insert(const T &x) {
        Tree nd = new Node(x, rnd.get());
        insert(root, nd);
    }
    inline void erase(const T &x) {
        erase(root, x);
    }
    inline int count(const T &x) {
        return count(root, x);
    }
    inline int order_of_key(const T &x) {
        return order_of_key(root, x);
    }
    inline T find_by_order(const int &x) {
        return find_by_order(root, x);
    }
    inline void get(int l, int r) {
        get(root, l, r);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/Treap.cpp"

struct Xorshift {
    unsigned int get() {
        static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        unsigned int t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }
};
template <class T>
struct Treap {
    Xorshift rnd;
    struct Node {
        T key;
        unsigned int pri;
        int siz;
        Node *l, *r;
        Node(T key, int pri) : key(key), pri(pri), siz(1), l(nullptr), r(nullptr) {}
    } *root = nullptr;
    using Tree = Node *;
    inline T nxt(T x) { return x + 1; }
    inline int size(Tree t) {
        return !t ? 0 : t->siz;
    }
    inline void eval(Tree t) {
        if (!t) return;
        t->siz = 1 + size(t->l) + size(t->r);
    }
    Tree merge(Tree l, Tree r) { //l内のkey < r内のkey
        if (!l || !r) {
            return !l ? r : l;
        }
        if (l->pri > r->pri) {
            l->r = merge(l->r, r);
            eval(l);
            return l;
        } else {
            r->l = merge(l, r->l);
            eval(r);
            return r;
        }
    }
    pair<Tree, Tree> split(Tree t, const T &x) { //key<x,x<=key でsplit
        if (!t) return make_pair(nullptr, nullptr);
        Tree tl, tr;
        tl = tr = nullptr;
        if (t->key < x) {
            tie(tl, tr) = split(t->r, x);
            t->r = tl;
            eval(t);
            tl = t;
        } else {
            tie(tl, tr) = split(t->l, x);
            t->l = tr;
            eval(t);
            tr = t;
        }
        return make_pair(tl, tr);
    }
    void insert(Tree &t, Tree nd) {
        Tree tl, tr;
        tl = tr = nullptr;
        tie(tl, tr) = split(t, nd->key);
        t = merge(merge(tl, nd), tr);
    }
    void erase(Tree &t, const T &x) {
        Tree tl, tm, tr;
        tl = tm = tr = nullptr;
        tie(tl, tm) = split(t, x);
        tie(tm, tr) = split(tm, nxt(x));
        t = merge(tl, tr);
    }
    int count(Tree t, const T &x) {
        if (!t) return 0;
        if (t->key == x) return 1;
        if (x < t->key) {
            return count(t->l, x);
        } else {
            return count(t->r, x);
        }
    }
    int order_of_key(Tree t, const T &x) {
        if (!t) return 0;
        if (x < t->key) {
            return order_of_key(t->l, x);
        } else if (x == t->key) {
            return size(t->l);
        } else {
            return size(t->l) + 1 + order_of_key(t->r, x);
        }
    }
    T find_by_order(Tree t, const int &x) {
        if (x < size(t->l)) {
            return find_by_order(t->l, x);
        } else if (x == size(t->l)) {
            return t->key;
        } else {
            return find_by_order(t->r, x - size(t->l) - 1);
        }
    }
    void get(Tree &t, int l, int r) { //[l,r)
        Tree tl, tm, tr;
        tie(tl, tm) = split(t, l);
        tie(tm, tr) = split(tm, r);
        //tm の情報を取得
        t = merge(tl, merge(tm, tr));
    }
    inline void insert(const T &x) {
        Tree nd = new Node(x, rnd.get());
        insert(root, nd);
    }
    inline void erase(const T &x) {
        erase(root, x);
    }
    inline int count(const T &x) {
        return count(root, x);
    }
    inline int order_of_key(const T &x) {
        return order_of_key(root, x);
    }
    inline T find_by_order(const int &x) {
        return find_by_order(root, x);
    }
    inline void get(int l, int r) {
        get(root, l, r);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


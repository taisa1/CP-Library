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


# :warning: DataStructure/ImplicitTreap.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/ImplicitTreap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 01:54:08+09:00




## Description
モノイドを Treap 上で管理する。  
各ノードは、ある区間を表し、区間内の演算結果を持つ。    
eval(t) : ノード t について、ノードに持つ情報を再計算する。  
insert(x,m) : Treap に key=x,val=m なるノードを挿入する。  
erase(x) : Treap 内の key=x なるノードを全て削除する。  
count(x) : Treap 内の key=x なるノードの個数を返す。  
order_of_key(x) : Treap 内で、 key が x 未満のノードの個数を返す。  
find_by_order(x) : Treap 内で、 x 番目に大きい key を返す。  
get(l,r) : Treap内で、 key が [l,r) の範囲内であるノードについての演算結果を返す。


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//@docs Docs/ImplicitTreap.md
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
template <class T, class M>
struct Treap {
    Xorshift rnd;
    struct Node {
        T key;
        unsigned int pri;
        M val, acc;
        int siz;
        Node *l, *r;
        Node(T key, int pri, M val) : key(key), pri(pri), siz(1), l(nullptr), r(nullptr), val(val), acc(val) {}
    } *root = nullptr;
    using Tree = Node *;
    inline T nxt(T x) { return x + 1; }
    inline int size(Tree t) {
        return !t ? 0 : t->siz;
    }
    inline M acc(Tree t) {
        return !t ? M::id() : t->acc;
    }
    inline void eval(Tree t) {
        if (!t) return;
        t->siz = 1 + size(t->l) + size(t->r);
        t->acc = M::f(M::f(acc(t->l), t->val), acc(t->r));
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
    M get(Tree &t, int l, int r) { //[l,r)
        Tree tl, tm, tr;
        tie(tl, tm) = split(t, l);
        tie(tm, tr) = split(tm, r);
        M res = acc(tm);
        t = merge(tl, merge(tm, tr));
        return res;
    }
    inline void insert(const T &x, const M &m) {
        Tree nd = new Node(x, rnd.get(), m);
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
    inline M get(int l, int r) { //[l,r)
        return get(root, l, r);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/ImplicitTreap.cpp"
//@docs Docs/ImplicitTreap.md
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
template <class T, class M>
struct Treap {
    Xorshift rnd;
    struct Node {
        T key;
        unsigned int pri;
        M val, acc;
        int siz;
        Node *l, *r;
        Node(T key, int pri, M val) : key(key), pri(pri), siz(1), l(nullptr), r(nullptr), val(val), acc(val) {}
    } *root = nullptr;
    using Tree = Node *;
    inline T nxt(T x) { return x + 1; }
    inline int size(Tree t) {
        return !t ? 0 : t->siz;
    }
    inline M acc(Tree t) {
        return !t ? M::id() : t->acc;
    }
    inline void eval(Tree t) {
        if (!t) return;
        t->siz = 1 + size(t->l) + size(t->r);
        t->acc = M::f(M::f(acc(t->l), t->val), acc(t->r));
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
    M get(Tree &t, int l, int r) { //[l,r)
        Tree tl, tm, tr;
        tie(tl, tm) = split(t, l);
        tie(tm, tr) = split(tm, r);
        M res = acc(tm);
        t = merge(tl, merge(tm, tr));
        return res;
    }
    inline void insert(const T &x, const M &m) {
        Tree nd = new Node(x, rnd.get(), m);
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
    inline M get(int l, int r) { //[l,r)
        return get(root, l, r);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


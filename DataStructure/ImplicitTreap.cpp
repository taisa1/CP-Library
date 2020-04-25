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
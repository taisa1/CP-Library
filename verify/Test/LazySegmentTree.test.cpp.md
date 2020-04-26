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


# :heavy_check_mark: Test/LazySegmentTree.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/LazySegmentTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 01:54:08+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/LazySegmentTree.cpp.html">DataStructure/LazySegmentTree.cpp</a>
* :heavy_check_mark: <a href="../../library/Math/Modint.cpp.html">Math/Modint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define fs first
#define sc second
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
constexpr ll INF = (1LL << 60) - 1LL;
constexpr ll MOD = 998244353LL;
constexpr int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
template <class T>
void chmin(T &a, T b) { a = min(a, b); }
template <class T>
void chmax(T &a, T b) { a = max(a, b); }
void debug() { cerr << "ok" << endl; }
template <class T>
void printv(const vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
}
#define call_from_test
#include "../DataStructure/LazySegmentTree.cpp"
#include "../Math/Modint.cpp"
#undef call_from_test
struct E {
    mint a, b;
    E() {}
    E(mint a, mint b) : a(a), b(b) {}
    inline static E id() {
        return E(1, 0);
    }
    inline static E f(const E &x, const E &y) {
        return E(x.a * y.a, y.a * x.b + y.b);
    }
};
struct T {
    mint a;
    T() {}
    T(mint a) : a(a) {}
    inline static T id() {
        return T(0);
    }
    inline static T f(const T &x, const T &y) {
        return T(x.a + y.a);
    }
    inline static T g(const T &x, const E &y, ll len) {
        return T(y.a * x.a + y.b * len);
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<T> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].a;
    }
    Segtree<T, E> seg(n, a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, c, d;
            cin >> l >> r >> c >> d;
            E x = E(c, d);
            seg.upd(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.get(l, r).a << '\n';
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/LazySegmentTree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define fs first
#define sc second
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
constexpr ll INF = (1LL << 60) - 1LL;
constexpr ll MOD = 998244353LL;
constexpr int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
template <class T>
void chmin(T &a, T b) { a = min(a, b); }
template <class T>
void chmax(T &a, T b) { a = max(a, b); }
void debug() { cerr << "ok" << endl; }
template <class T>
void printv(const vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
}
#define call_from_test
#line 1 "DataStructure/LazySegmentTree.cpp"
//@docs Docs/LazySegmentTree.md
template <class T, class E>
struct Segtree {
    int n, h;
    vector<T> dat;
    vector<E> laz;
    vector<ll> len;
    Segtree(int n_) {
        n = 1;
        h = 1;
        while (n < n_) {
            n <<= 1;
            h++;
        }
        dat.resize(2 * n, T::id());
        laz.resize(2 * n, E::id());
        len.resize(2 * n, 1);
        for (int i = n - 1; i > 0; i--) len[i] = len[i << 1] + len[i << 1 | 1];
    }
    Segtree(int n_, const vector<T> &a) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, T::id());
        laz.resize(2 * n, E::id());
        len.resize(2 * n, 1);
        for (int i = 0; i < a.size(); i++) dat[i + n] = a[i];
        for (int i = n - 1; i > 0; i--) {
            len[i] = len[i << 1] + len[i << 1 | 1];
            dat[i] = T::f(dat[i << 1], dat[i << 1 | 1]);
        }
    }
    inline void eval(int k) {
        dat[k] = T::g(dat[k], laz[k], len[k]);
        if (k < n) {
            laz[k << 1] = E::f(laz[k << 1], laz[k]);
            laz[k << 1 | 1] = E::f(laz[k << 1 | 1], laz[k]);
        }
        laz[k] = E::id();
    }
    void upd(const int &a, const int &b, const E &x, int k, int l, int r) {
        eval(k);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            laz[k] = E::f(laz[k], x);
            eval(k);
            return;
        }
        upd(a, b, x, k << 1, l, (l + r) >> 1);
        upd(a, b, x, k << 1 | 1, (l + r) >> 1, r);
        dat[k] = T::f(dat[k << 1], dat[k << 1 | 1]);
    }
    T get(const int &a, const int &b, int k, int l, int r) {
        eval(k);
        if (b <= l || r <= a) {
            return T::id();
        }
        if (a <= l && r <= b) {
            return dat[k];
        }
        return T::f(get(a, b, k << 1, l, (l + r) >> 1), get(a, b, k << 1 | 1, (l + r) >> 1, r));
    }
    int find(const int &a, const int &b, const T &x, int k, int l, int r) {
        eval(k);
        if (b <= l || r <= a || dat[k] > x) {
            return -1;
        }
        if (k >= n) {
            return k - n;
        }
        int il = find(a, b, x, k << 1, l, (l + r) >> 1);
        if (il != -1) {
            return il;
        }
        return find(a, b, x, k << 1 | 1, (l + r) >> 1, r);
    }
    void setval(int k, const T &x) {
        k += n;
        for (int i = h; i >= 0; i--) eval(k >> i);
        dat[k] = x;
        while (k > 1) {
            k >>= 1;
            dat[k] = T::f(dat[k << 1], dat[k << 1 | 1]);
        }
    }
    inline void upd(const int &a, const int &b, const E &x) {
        if (a >= b) {
            return;
        }
        upd(a, b, x, 1, 0, n);
    }
    inline T get(const int &a, const int &b) {
        if (a >= b) {
            return T::id();
        }
        return get(a, b, 1, 0, n);
    }
    inline int find(const int &a, const int &b, const T &x) { //[a,b)における、値<=x なる最左のindexを求める
        if (a >= b) {
            return -1;
        }
        return find(a, b, x, 1, 0, n);
    }
};
#line 1 "Math/Modint.cpp"
//from http://noshi91.hatenablog.com/entry/2019/03/31/174006
template <std::uint_fast64_t Modulus>
class modint {
    using u64 = std::uint_fast64_t;

  public:
    u64 a;
    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint operator^(const u64 rhs) const noexcept {
        return modint(*this) ^= rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    constexpr modint &operator^=(u64 exp) {
        modint rhs = modint(*this);
        a = 1;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &os, const modint &x) {
        os << x.a;
        return os;
    }
    friend istream &operator>>(istream &is, modint &x) {
        is >> x.a;
        return is;
    }
};
using mint = modint<MOD>;
#line 28 "Test/LazySegmentTree.test.cpp"
#undef call_from_test
struct E {
    mint a, b;
    E() {}
    E(mint a, mint b) : a(a), b(b) {}
    inline static E id() {
        return E(1, 0);
    }
    inline static E f(const E &x, const E &y) {
        return E(x.a * y.a, y.a * x.b + y.b);
    }
};
struct T {
    mint a;
    T() {}
    T(mint a) : a(a) {}
    inline static T id() {
        return T(0);
    }
    inline static T f(const T &x, const T &y) {
        return T(x.a + y.a);
    }
    inline static T g(const T &x, const E &y, ll len) {
        return T(y.a * x.a + y.b * len);
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<T> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].a;
    }
    Segtree<T, E> seg(n, a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, c, d;
            cin >> l >> r >> c >> d;
            E x = E(c, d);
            seg.upd(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.get(l, r).a << '\n';
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


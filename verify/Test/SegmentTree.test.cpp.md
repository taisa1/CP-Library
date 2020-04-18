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


# :heavy_check_mark: Test/SegmentTree.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/SegmentTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 12:56:31+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/SegmentTree.cpp.html">DataStructure/SegmentTree.cpp</a>
* :heavy_check_mark: <a href="../../library/Math/ModInt.cpp.html">Math/ModInt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
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
#include "../DataStructure/SegmentTree.cpp"
#include "../Math/ModInt.cpp"
#undef call_from_test
struct T {
    mint a, b;
    inline static T f(const T &a, const T &b) {
        return T(a.a * b.a, b.a * a.b + b.b);
    }
    inline static void g(T &a, const T &b) {
        a = b;
    }
    T(const mint &aa, const mint &bb) : a(aa), b(bb) {}
    static T e;
};
T T::e = T(1, 0);
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    Segtree<T> seg(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        seg.upd(i, T(a, b));
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            seg.upd(p, T(c, d));
        } else {
            int l, r;
            cin >> l >> r;
            T t = seg.get(l, r);
            ll x;
            cin >> x;
            cout << (t.a * x + t.b) << '\n';
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/SegmentTree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
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
#line 1 "DataStructure/SegmentTree.cpp"
//Point Update Range Get
template <class T>
struct Segtree {
    int n;
    vector<T> dat;
    Segtree(int n_) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, T::e);
    }
    Segtree(int n_, const vector<T> &a) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, T::e);
        for (int i = 0; i < a.size(); i++) {
            dat[i + n] = a[i];
        }
        for (int i = n - 1; i > 0; i--) {
            dat[i] = T::f(dat[i << 1], dat[i << 1 | 1]);
        }
    }
    void upd(int k, const T &x) {
        k += n;
        T::g(dat[k], x);
        k >>= 1;
        while (k > 0) {
            dat[k] = T::f(dat[k << 1], dat[k << 1 | 1]);
            k >>= 1;
        }
    }
    T get(const int &a, const int &b, int k, int l, int r) {
        if (b <= l || r <= a) {
            return T::e;
        }
        if (a <= l && r <= b) {
            return dat[k];
        }
        return T::f(get(a, b, k << 1, l, (l + r) >> 1),
                    get(a, b, k << 1 | 1, (l + r) >> 1, r));
    }
    inline T get(const int &a, const int &b) { //[a,b)
        if (a >= b) {
            return T::e;
        }
        return get(a, b, 1, 0, n);
    }
    int find(const int &a, const int &b, const T &x, int k, int l, int r) {
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
    inline int find(const int &a, const int &b, const T &x) { //[a,b)における、値<=x なる最左のindexを求める
        if (a >= b) {
            return -1;
        }
        return find(a, b, x, 1, 0, n);
    }
};
#line 1 "Math/ModInt.cpp"
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
};
using mint = modint<MOD>;
#line 28 "Test/SegmentTree.test.cpp"
#undef call_from_test
struct T {
    mint a, b;
    inline static T f(const T &a, const T &b) {
        return T(a.a * b.a, b.a * a.b + b.b);
    }
    inline static void g(T &a, const T &b) {
        a = b;
    }
    T(const mint &aa, const mint &bb) : a(aa), b(bb) {}
    static T e;
};
T T::e = T(1, 0);
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    Segtree<T> seg(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        seg.upd(i, T(a, b));
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            seg.upd(p, T(c, d));
        } else {
            int l, r;
            cin >> l >> r;
            T t = seg.get(l, r);
            ll x;
            cin >> x;
            cout << (t.a * x + t.b) << '\n';
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


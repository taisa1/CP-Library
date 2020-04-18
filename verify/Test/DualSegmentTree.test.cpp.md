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


# :heavy_check_mark: Test/DualSegmentTree.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/DualSegmentTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 23:39:09+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/DualSegmentTree.cpp.html">DataStructure/DualSegmentTree.cpp</a>
* :heavy_check_mark: <a href="../../library/Math/ModInt.cpp.html">Math/ModInt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"
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
#include "../DataStructure/DualSegmentTree.cpp"
#include "../Math/ModInt.cpp"
#undef call_from_test
struct T {
    int a, b;
    inline static T f(const T &x, const T &y) {
        return x.a > y.a ? x : y;
    }
    inline void g(const T &x) { a = x.a, b = x.b; }
    static T e;
};
T T::e = T{-1, (1LL << 31) - 1LL};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    Segtree<T> seg(n);
    for (int co = 0; co < q; co++) {
        int ty;
        cin >> ty;
        if (ty == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            seg.upd(s, t + 1, T{co, x});
        } else {
            int i;
            cin >> i;
            cout << seg.get(i).b << '\n';
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/DualSegmentTree.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"
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
#line 1 "DataStructure/DualSegmentTree.cpp"
//Range Update Point Get
template <typename T>
struct Segtree {
    vector<T> dat;
    int n;
    T e;
    Segtree(int n_) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, T::e);
    }
    void upd(const int &a, const int &b, const T &x, int k, int l, int r) {
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            dat[k].g(x);
            return;
        }
        upd(a, b, x, k << 1, l, (l + r) >> 1);
        upd(a, b, x, k << 1 | 1, (l + r) >> 1, r);
    }
    inline void upd(const int &a, const int &b, const T &x) {
        if (a >= b) {
            return;
        }
        upd(a, b, x, 1, 0, n);
    }
    T get(int k) {
        k += n;
        T res = dat[k];
        k >>= 1;
        while (k > 0) {
            res = T::f(res, dat[k]);
            k >>= 1;
        }
        return res;
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
    friend istream &operator>>(istream &is, modint &x) {
        is >> x.a;
        return is;
    }
};
using mint = modint<MOD>;
#line 28 "Test/DualSegmentTree.test.cpp"
#undef call_from_test
struct T {
    int a, b;
    inline static T f(const T &x, const T &y) {
        return x.a > y.a ? x : y;
    }
    inline void g(const T &x) { a = x.a, b = x.b; }
    static T e;
};
T T::e = T{-1, (1LL << 31) - 1LL};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    Segtree<T> seg(n);
    for (int co = 0; co < q; co++) {
        int ty;
        cin >> ty;
        if (ty == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            seg.upd(s, t + 1, T{co, x});
        } else {
            int i;
            cin >> i;
            cout << seg.get(i).b << '\n';
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


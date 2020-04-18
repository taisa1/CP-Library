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


# :heavy_check_mark: Test/SWAG.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/SWAG.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 13:33:28+09:00


* see: <a href="https://judge.yosupo.jp/problem/queue_operate_all_composite">https://judge.yosupo.jp/problem/queue_operate_all_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/SlidingWindowAggregation.cpp.html">DataStructure/SlidingWindowAggregation.cpp</a>
* :heavy_check_mark: <a href="../../library/Math/ModInt.cpp.html">Math/ModInt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
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
#include "../DataStructure/SlidingWindowAggregation.cpp"
#include "../Math/ModInt.cpp"
#undef call_from_test
struct T {
    mint a, b;
    inline static T f(const T &a, const T &b) {
        return T{a.a * b.a, b.a * a.b + b.b};
    }
    static T e;
};
T T::e = T{1, 0};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    SWAG<T> q;
    while (t--) {
        int ty;
        cin >> ty;
        if (ty == 0) {
            ll a, b;
            cin >> a >> b;
            q.push(T{mint(a), mint(b)});
        } else if (ty == 1) {
            q.pop();
        } else {
            ll x;
            cin >> x;
            T r = q.fold();
            cout << (r.a * x + r.b).a << '\n';
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/SWAG.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
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
#line 1 "DataStructure/SlidingWindowAggregation.cpp"
template <class T>
struct SWAG {
    SWAG() {}
    stack<pair<T, T>> frontst, backst;
    void push(const T &x) {
        if (backst.empty()) {
            backst.emplace(x, x);
        } else {
            backst.emplace(x, T::f(backst.top().second, x));
        }
    }
    void pop() {
        if (frontst.empty()) {
            while (!backst.empty()) {
                if (frontst.empty()) {
                    frontst.emplace(backst.top().first, backst.top().first);
                } else {
                    frontst.emplace(backst.top().first, T::f(backst.top().first, frontst.top().second));
                }
                backst.pop();
            }
        }
        frontst.pop();
    }
    T fold() {
        if (frontst.empty() && backst.empty()) {
            return T::e;
        }
        if (frontst.empty()) {
            return backst.top().second;
        } else if (backst.empty()) {
            return frontst.top().second;
        }
        return T::f(frontst.top().second, backst.top().second);
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
#line 28 "Test/SWAG.test.cpp"
#undef call_from_test
struct T {
    mint a, b;
    inline static T f(const T &a, const T &b) {
        return T{a.a * b.a, b.a * a.b + b.b};
    }
    static T e;
};
T T::e = T{1, 0};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    SWAG<T> q;
    while (t--) {
        int ty;
        cin >> ty;
        if (ty == 0) {
            ll a, b;
            cin >> a >> b;
            q.push(T{mint(a), mint(b)});
        } else if (ty == 1) {
            q.pop();
        } else {
            ll x;
            cin >> x;
            T r = q.fold();
            cout << (r.a * x + r.b).a << '\n';
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


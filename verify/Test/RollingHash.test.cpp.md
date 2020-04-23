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


# :heavy_check_mark: Test/RollingHash.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#0cbc6611f5540bd0809a388dc95a615b">Test</a>
* <a href="{{ site.github.repository_url }}/blob/master/Test/RollingHash.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 12:58:47+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :heavy_check_mark: <a href="../../library/String/RollingHash.cpp.html">String/RollingHash.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
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
constexpr ll INF = (1LL << 30) - 1LL;
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
#include "../String/RollingHash.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    V<int> a(n);
    RollingHash ro(s);
    for (int i = 0; i < n; i++) {
        int ok = i - 1, ng = n;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (ro.get(i, mid) == ro.get(0, mid - i)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        a[i] = ok - i + 1;
    }
    printv(a);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Test/RollingHash.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
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
constexpr ll INF = (1LL << 30) - 1LL;
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
#line 1 "String/RollingHash.cpp"
using ull = uint64_t;
const int bases[64] = {257, 262, 266, 275, 276, 281, 285, 290, 296, 302, 306,
                       310, 311, 313, 323, 333, 344, 345, 350, 357, 367, 370,
                       373, 402, 423, 425, 431, 440, 442, 443, 454, 457, 458,
                       462, 471, 478, 481, 487, 489, 492, 499, 501, 502, 503,
                       506, 514, 524, 532, 535, 541, 550, 552, 557, 559, 562,
                       563, 567, 570, 571, 580, 592, 597, 604, 612};
const ull rmod = 0x1fffffffffffffff;
const ull base = bases[chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count() & 63];
const ull mask30 = (1UL << 30) - 1, mask31 = (1UL << 31) - 1;
struct RollingHash {
    vector<ull> hash, pow;
    inline ull mul(const ull &a, const ull &b) const {
        ull mid = (a & mask31) * (b >> 31) + (a >> 31) * (b & mask31);
        ull res = (a >> 31) * (b >> 31) * 2 + (mid >> 30) + ((mid & mask30) << 31);
        res += (a & mask31) * (b & mask31);
        res = (res >> 61) + (res & rmod);
        if (res >= rmod) res -= rmod;
        return res;
    }
    RollingHash(const string &s) {
        hash.resize(s.length() + 1);
        pow.resize(s.length() + 1);
        pow[0] = 1;
        for (int i = 0; i < s.length(); i++) {
            hash[i + 1] = mul(hash[i], base) + s[i];
            pow[i + 1] = mul(pow[i], base);
            if (hash[i + 1] >= rmod) hash[i + 1] -= rmod;
        }
    }
    ull get(int l, int r) { //[l,r]
        ull res = hash[r + 1] + rmod - mul(hash[l], pow[r + 1 - l]);
        if (res >= rmod) res -= rmod;
        return res;
    }
};
#line 27 "Test/RollingHash.test.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    V<int> a(n);
    RollingHash ro(s);
    for (int i = 0; i < n; i++) {
        int ok = i - 1, ng = n;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (ro.get(i, mid) == ro.get(0, mid - i)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        a[i] = ok - i + 1;
    }
    printv(a);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


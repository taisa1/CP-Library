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


# :x: Tests/BinaryIndexedTree.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#90792de52961c34118f976ebe4af3a75">Tests</a>
* <a href="{{ site.github.repository_url }}/blob/master/Tests/BinaryIndexedTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 10:49:59+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_add_range_sum">https://judge.yosupo.jp/problem/point_add_range_sum</a>


## Depends on

* :x: <a href="../../library/DataStructure/BinaryIndexedTree.cpp.html">DataStructure/BinaryIndexedTree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#define call_fromm_test
#include "../DataStructure/BinaryIndexedTree.cpp"
#undef call_from_test
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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    BinaryIndexedTree<ll> bit(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bit.add(i, a[i]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            bit.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << bit.get(r - 1) - bit.get(l - 1) << '\n';
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Tests/BinaryIndexedTree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#define call_fromm_test
#line 1 "DataStructure/BinaryIndexedTree.cpp"
//Point Add Range Sum
template <typename T>
struct BinaryIndexedTree {
    vector<T> node;
    int n;
    BinaryIndexedTree(int n) : n(n) { node.assign(++n, 0); }
    void add(int k, T x) {
        for (++k; k < n; k += k & -k) {
            node[k] += x;
        }
    }
    T get(int k) {
        T res = 0;
        for (++k; k > 0; k -= k & -k) {
            res += node[k];
        }
        return res;
    }
};
#line 5 "Tests/BinaryIndexedTree.test.cpp"
#undef call_from_test
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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    BinaryIndexedTree<ll> bit(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bit.add(i, a[i]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            bit.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << bit.get(r - 1) - bit.get(l - 1) << '\n';
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


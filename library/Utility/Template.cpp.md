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


# :warning: Utility/Template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#94df2a6972ca1fa79411645fe9b42339">Utility</a>
* <a href="{{ site.github.repository_url }}/blob/master/Utility/Template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 01:10:06+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Utility/Template.cpp"
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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


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
#include "../Math/ModInt.cpp"
#undef call_from_test
struct E {
    mint a, b;
    inline void h(const E &y) {
        a = a * y.a;
        b = y.a * b + y.b;
    }
    static E e;
};
struct T {
    mint a;
    inline static T f(const T &x, const T &y) {
        return T{x.a + y.a};
    }
    inline void g(const E &x, ll len) {
        a = x.a * a + x.b * len;
    }
    static T e;
};
E E::e = E{1, 0};
T T::e = T{0};
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
            E x = E{c, d};
            seg.upd(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.get(l, r).a << '\n';
        }
    }
}
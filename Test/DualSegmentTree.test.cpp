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
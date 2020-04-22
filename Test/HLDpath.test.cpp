#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
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
template <class T>
void readv(vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}
#define call_from_test
#include "../DataStructure/BinaryIndexedTree.cpp"
#include "../Graph/HeavyLightDecomposition.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    V<ll> a(n);
    readv(a);
    HLD g(n);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v);
    }
    BinaryIndexedTree<ll> bit(n);
    for (int i = 0; i < n; i++) {
        bit.add(g.index(i), a[i]);
    }
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            bit.add(g.index(u), v);
        } else {
            ll res = 0;
            auto f = [&](int a, int b) { res += bit.get(a, b); };
            g.getpath(u, v, f);
            cout << res << '\n';
        }
    }
}
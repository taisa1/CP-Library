#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
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
constexpr ll INF = (1LL << 62) - 1LL;
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
#include "../DataStructure/LiChaoTree.cpp"
#undef call_from_test
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n), t(q), p(q), c(q), d(q);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    CHT cht;
    for (int i = 0; i < q; i++) {
        cin >> t[i];
        if (t[i] == 0) {
            cin >> c[i] >> d[i];
        } else {
            cin >> p[i];
            cht.preadd(p[i]);
        }
    }
    cht.build();
    for (int i = 0; i < n; i++) {
        cht.add(a[i], b[i]);
    }
    for (int i = 0; i < q; i++) {
        if (t[i] == 0) {
            cht.add(c[i], d[i]);
        } else {
            cout << cht.get(p[i]) << '\n';
        }
    }
}
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
#include "../Math/Modint.cpp"
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
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
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1330"
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
#include "../DataStructure/PotentializedUnionFind.cpp"
#undef call_from_test
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (1) {
        cin >> n >> m;
        if (n == 0) return 0;
        UnionFind<int> uf(n);
        for (int i = 0; i < m; i++) {
            char c;
            cin >> c;
            if (c == '!') {
                int a, b, w;
                cin >> a >> b >> w;
                --a;
                --b;
                uf.unite(a, b, w);
            } else {
                int a, b;
                cin >> a >> b;
                --a;
                --b;
                if (uf.same(a, b)) {
                    cout << uf.value(b) - uf.value(a) << '\n';
                } else {
                    cout << "UNKNOWN\n";
                }
            }
        }
    }
}
//@docs Docs/SparseTable.md
const int LOG = 30;
template <class T>
struct SparseTable {
    int n;
    vector<vector<T>> dat;
    vector<int> lg, p;
    SparseTable(const int &n, const T &e) : n(n), lg(n + 1), p(LOG) {
        dat.resize(LOG, vector<T>(n, e));
        for (int i = 1; i <= n; i++) {
            lg[i] = 31 - __builtin_clz(i);
        }
        p[0] = 1;
        for (int i = 1; i < LOG; i++) {
            p[i] = p[i - 1] * 2;
        }
    }
    void build(const vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            dat[0][i] = a[i];
        }
        for (int i = 1; i <= lg[n]; i++) {
            for (int j = 0; j < n; j++) {
                if (j + p[i - 1] >= n) continue;
                dat[i][j] = min(dat[i - 1][j], dat[i - 1][j + p[i - 1]]);
            }
        }
    }
    T get(const int &l, const int &r) { //0-indexed [l,r)
        return min(dat[lg[r - l]][l], dat[lg[r - l]][r - p[lg[r - l]]]);
    }
};
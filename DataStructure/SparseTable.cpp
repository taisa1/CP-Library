template <class T>
struct SparseTable {
    int n;
    vector<vector<T>> dat;
    vector<int> lg, p;
    ST(int n, T e) : n(n) {
        dat.resize(30, vector<ll>(n, e));
        lg.resize(n + 10);
        p.resize(n + 10);
        for (int i = 1; i <= n; i++) {
            lg[i] = log2(i);
        }
        p[0] = 1;
        for (int i = 1; i < 30; i++) {
            p[i] = p[i - 1] * 2;
        }
    }
    void build(const vector<T> &a) {
        for (int i = 0; i < n; i++) {
            dat[0][i] = a[i];
        }
        for (int i = 1; i <= lg[n]; i++) {
            for (int j = 0; j < n; j++) {
                if (j + p[i - 1] >= n) continue;
                dat[i][j] = min(dat[i - 1][j], dat[i - 1][j + p[i - 1]]);
            }
        }
    }
    T get(int l, int r) {
        return min(dat[lg[r - l]][l], dat[lg[r - l]][r - p[lg[r - l]]]);
    }
};
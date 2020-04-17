const int maxH = 100030, maxW = 310;
struct BitMatrix {
    bitset<maxW> a[maxH];
    int n, m;
    BitMatrix(int n_, int m_) : n(n_), m(m_) {}
    inline bitset<maxW> &operator[](int i) { return a[i]; }
};

//bitmatrix を掃き出し、rankを返す
int GaussJordan(BitMatrix &a, bool extended) {
    int rank = 0;
    for (int j = 0; j < a.m; j++) {
        if (extended && j + 1 == a.m) break;
        int piv = -1;
        for (int i = rank; i < a.n; i++) {
            if (a[i][j]) {
                piv = i;
                break;
            }
        }
        if (piv == -1) continue;
        swap(a[rank], a[piv]);
        piv = rank;
        for (int i = 0; i < a.n; i++) {
            if (i == piv) continue;
            if (a[i][j]) {
                a[i] ^= a[piv];
            }
        }
        rank++;
    }
    return rank;
}
//ax=b なるベクトルxを求め、自由度を返す O(HW^2) a:H*W b:H*1 x:W*1
int LinearEquation(BitMatrix a, vector<int> b, vector<int> &x) {
    BitMatrix na(a.n, a.m + 1);
    for (int i = 0; i < a.n; i++) {
        na[i] = a[i];
        na[i][a.m] = b[i];
    }
    int rank = GaussJordan(na, true);
    for (int i = rank; i < a.n; i++) {
        if (na[i][a.m]) return -1;
    }
    x.assign(a.m, 0);
    for (int i = 0; i < rank; i++) {
        x[i] = na[i][a.m];
    }
    return a.m - rank;
}
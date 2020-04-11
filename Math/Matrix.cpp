template <class T>
struct Matrix {
    vector<vector<T>> a;
    Matrix() {}
    Matrix(int n, int m) : a(n, vector<T>(m)) {}
    inline const vector<T> &operator[](int k) const {
        return a.at(k);
    }
    inline vector<T> &operator[](int k) {
        return a.at(k);
    }
    Matrix I(int n) {
        Matrix mat(n, n);
        for (int i = 0; i < n; i++) {
            mat[i][i] = 1;
        }
        return mat;
    }
    Matrix &operator+=(const Matrix &rhs) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[i].size(); j++) {
                (*this)[i][j] += rhs[i][j];
            }
        }
        return (*this);
    }
    Matrix &operator-=(const Matrix &rhs) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[i].size(); j++) {
                (*this)[i][j] -= rhs[i][j];
            }
        }
        return (*this);
    }
    Matrix &operator*=(const Matrix &rhs) {
        int n = a.size(), m = a[0].size(), p = rhs[0].size();
        assert(m == rhs.a.size());
        vector<vector<T>> b(n, vector<T>(p));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < m; k++) {
                    b[i][j] += (*this)[i][k] * rhs[k][j];
                }
            }
        }
        swap(a, b);
        return (*this);
    }
    Matrix &operator^=(const long long &rhs) {
        long long n = rhs;
        Matrix res = Matrix::I(a.size());
        while (n > 0) {
            if (n & 1) {
                res *= (*this);
            }
            (*this) *= (*this);
            n >>= 1;
        }
        swap(a, res.a);
        return (*this);
    }
    Matrix operator+(const Matrix &rhs) const {
        return Matrix(*this) += rhs;
    }
    Matrix operator-(const Matrix &rhs) const {
        return Matrix(*this) -= rhs;
    }
    Matrix operator*(const Matrix &rhs) const {
        return Matrix(*this) *= rhs;
    }
    Matrix operator^(const long long &rhs) const {
        return Matrix(*this) ^= rhs;
    }
};
//size fixed
template <class T, int N, int M>
struct Matrix : array<array<T, N>, M> {
    using array<array<T, N>, M>::size;
    Matrix() {
        for (int i = 0; i < N; i++) {
            fill((*this)[i].begin(), (*this)[i].end(), 0);
        }
    }
    inline int h() const { return int(size()); }
    inline int w() const { return int((*this)[0].size()); }
    static Matrix I() {
        assert(N == M);
        Matrix mat = Matrix();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                mat[i][j] = 0;
            }
            mat[i][i] = 1;
        }
        return mat;
    }
    Matrix &operator+=(const Matrix &rhs) {
        for (int i = 0; i < h(); i++) {
            for (int j = 0; j < w(); j++) {
                (*this)[i][j] += rhs[i][j];
            }
        }
        return (*this);
    }
    Matrix &operator-=(const Matrix &rhs) {
        for (int i = 0; i < h(); i++) {
            for (int j = 0; j < w(); j++) {
                (*this)[i][j] -= rhs[i][j];
            }
        }
        return (*this);
    }
    Matrix operator*(const Matrix &rhs) const {
        int n = h(), m = w(), p = rhs.w();
        assert(m == rhs.h());
        Matrix res = Matrix();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < m; k++) {
                    res[i][j] += (*this)[i][k] * rhs[k][j];
                }
            }
        }
        return res;
    }
    Matrix &operator*=(const Matrix &rhs) {
        return (*this) = (*this) * rhs;
    }
    Matrix &operator^=(const long long &rhs) {
        long long n = rhs;
        Matrix res = Matrix::I(h());
        while (n > 0) {
            if (n & 1) {
                res *= (*this);
            }
            (*this) *= (*this);
            n >>= 1;
        }
        (*this) = res;
        return (*this);
    }
    Matrix operator+(const Matrix &rhs) const {
        return Matrix(*this) += rhs;
    }
    Matrix operator-(const Matrix &rhs) const {
        return Matrix(*this) -= rhs;
    }
    Matrix operator^(const long long &rhs) const {
        return Matrix(*this) ^= rhs;
    }
};
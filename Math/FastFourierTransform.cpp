struct FFT {
    using D = double;
    using C = complex<D>;
    static void dft(vector<C> &v, int inv) {
        int sz = v.size();
        if (sz == 1) return;
        int hf = sz / 2;
        vector<C> va(hf), vb(hf);
        for (int i = 0; i < hf; i++) {
            va[i] = v[i << 1];
            vb[i] = v[i << 1 | 1];
        }
        dft(va, inv);
        dft(vb, inv);
        C w = polar(1.0, 2.0 * acos(-1.0) * inv / sz), now = 1;
        for (int i = 0; i < sz; i++) {
            v[i] = va[i % hf] + now * vb[i % hf];
            now *= w;
        }
    }
    template <class T>
    static vector<T> convolution(vector<T> a, vector<T> b) {
        int na = a.size(), nb = b.size();
        int sz = 1, rn = na + nb - 1;
        while (sz < rn) sz <<= 1;
        vector<C> A(sz), B(sz);
        for (int i = 0; i < na; i++) A[i] = a[i];
        for (int i = 0; i < nb; i++) B[i] = b[i];
        dft(A, 1);
        dft(B, 1);
        for (int i = 0; i < sz; i++) A[i] *= B[i];
        dft(A, -1);
        a.resize(rn);
        for (int i = 0; i < rn; i++) a[i] = A[i].real() / sz;
        return a;
    }
};

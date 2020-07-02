constexpr mint proot = 3;
struct NTT {
    static void dft(vector<mint> &v, const int &inv) {
        int sz = v.size();
        if (sz == 1) return;
        int hf = sz / 2;
        vector<mint> va(hf), vb(hf);
        for (int i = 0; i < hf; i++) {
            va[i] = v[i << 1];
            vb[i] = v[i << 1 | 1];
        }
        dft(va, inv);
        dft(vb, inv);
        mint w = (inv > 0 ? proot : mint(1) / proot) ^ (mint(MOD - 1) / mint(sz)).a, now = 1;
        for (int i = 0; i < sz; i++) {
            v[i] = va[i % hf] + now * vb[i % hf];
            now *= w;
        }
    }
    static vector<mint> convolution(const vector<mint> &a, const vector<mint> &b) {
        int na = a.size(), nb = b.size();
        int sz = 1, rn = na + nb - 1;
        while (sz < rn) sz <<= 1;
        vector<mint> A(sz), B(sz);
        for (int i = 0; i < na; i++) A[i] = a[i];
        for (int i = 0; i < nb; i++) B[i] = b[i];
        dft(A, 1);
        dft(B, 1);
        for (int i = 0; i < sz; i++) A[i] *= B[i];
        dft(A, -1);
        vector<mint> res(rn);
        for (int i = 0; i < rn; i++) res[i] = A[i] / mint(sz);
        return res;
    }
};
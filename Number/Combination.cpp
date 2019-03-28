vector<mint> f, fi;
void comb(int n) {
    f.resize(n + 10);
    fi.resize(n + 10);
    f[0] = 1;
    for(ll i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i;
    }
    fi[n] = f[n].inv();
    for(ll i = n - 1; i >= 0; i--) {
        fi[i] = fi[i + 1] * (i + 1LL);
    }
}
mint ncr(ll n, ll r) {
    return f[n] * fi[r] * fi[n - r];
}
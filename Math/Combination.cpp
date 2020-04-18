ector<mint> f, fi;
void comb(int n) {
    f.resize(n + 1);
    fi.resize(n + 1);
    f[0] = 1;
    for (ll i = 1; i <= n; i++) {
        f[i] = f[i - 1] * mint(i);
    }
    fi[n] = mint(1) / f[n];
    for (ll i = n - 1; i >= 0; i--) {
        fi[i] = fi[i + 1] * mint(i + 1LL);
    }
}
mint ncr(ll n, ll r) {
    if (n < r) {
        return mint(0);
    }
    if (r == 0) {
        return mint(1);
    }
    return f[n] * fi[n - r] * fi[r];
}
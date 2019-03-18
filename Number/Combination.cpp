ll mpow(ll x, ll n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = res * x % MOD;
        }
        n >>= 1;
        x = x * x % MOD;
    }
    return res;
}
vector<ll> f, fi;
void comb(int n) {
    f.resize(n + 10);
    fi.resize(n + 10);
    f[0] = 1;
    for(ll i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }
    fi[n] = mpow(f[n], MOD - 2);
    for(ll i = n - 1; i >= 0; i--) {
        fi[i] = fi[i + 1] * (i + 1LL);
        fi[i] %= MOD;
    }
}
ll ncr(ll n, ll r) { return f[n] * fi[r] % MOD * fi[n - r] % MOD; }
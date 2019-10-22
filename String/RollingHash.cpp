const ll mod1 = 100000000000031LL, mod2 = 1000000000000037LL,
         base1 = 256LL + (random_device()() % 64),
         base2 = 256LL + (random_device()() % 64);
struct RollingHash {
    int n;
    string s;
    vector<ll> hash1, hash2, pow1, pow2;
    RollingHash(const string &str) {
        s = str;
        n = str.length();
        hash1.resize(n + 10);
        hash2.resize(n + 10);
        pow1.resize(n + 10, 1);
        pow2.resize(n + 10, 1);
        for (int i = 0; i < n; i++) {
            hash1[i + 1] = (__uint128_t)(hash1[i] + s[i]) * base1 % mod1;
            hash2[i + 1] = (__uint128_t)(hash2[i] + s[i]) * base2 % mod2;
            pow1[i + 1] = (__uint128_t)pow1[i] * base1 % mod1;
            pow2[i + 1] = (__uint128_t)pow2[i] * base2 % mod2;
        }
    }
    pair<ll, ll> get(int l, int r) {
        ll t1 = (hash1[r] - (__uint128_t)hash1[l] * pow1[r - l] % mod1 + mod1) %
                mod1;
        ll t2 = (hash2[r] - (__uint128_t)hash2[l] * pow2[r - l] % mod2 + mod2) %
                mod2;
        return make_pair(t1, t2);
    }
};
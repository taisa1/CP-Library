using ull = unsigned long long;
const int bases[64] = {257, 262, 266, 275, 276, 281, 285, 290, 296, 302, 306,
                       310, 311, 313, 323, 333, 344, 345, 350, 357, 367, 370,
                       373, 402, 423, 425, 431, 440, 442, 443, 454, 457, 458,
                       462, 471, 478, 481, 487, 489, 492, 499, 501, 502, 503,
                       506, 514, 524, 532, 535, 541, 550, 552, 557, 559, 562,
                       563, 567, 570, 571, 580, 592, 597, 604, 612};
const ull mod = 0x1fffffffffffffff,
          base = bases[chrono::duration_cast<chrono::microseconds>(
                           chrono::system_clock::now().time_since_epoch())
                           .count() &
                       63];
struct RollingHash {
    vector<ull> hashed, power;
    static constexpr ull mask(int a) { return (1ull << a) - 1; }
    inline ull mul(ull a, ull b) const {
        ull a31 = a >> 31, b31 = b >> 31;
        a &= mask(31);
        b &= mask(31);
        ull x = a * b31 + b * a31;
        ull ans = (a31 * b31 << 1) + (x >> 30) + ((x & mask(30)) << 31) + a * b;
        ans = (ans >> 61) + ans & mask(61);
        if (ans >= mod)
            ans -= mod;
        return ans;
    }
    RollingHash(const string &s) {
        ll n = s.size();
        hashed.assign(n + 1, 0);
        power.assign(n + 1, 0);
        power[0] = 1;
        for (ll i = 0; i < n; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if (hashed[i + 1] >= mod)
                hashed[i + 1] -= mod;
        }
    }

    ull get(ll l, ll r) const {
        ull ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if (ret >= mod)
            ret -= mod;
        return ret;
    }
};
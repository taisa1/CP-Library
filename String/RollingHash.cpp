using ull = uint64_t;
const int bases[64] = {257, 262, 266, 275, 276, 281, 285, 290, 296, 302, 306,
                       310, 311, 313, 323, 333, 344, 345, 350, 357, 367, 370,
                       373, 402, 423, 425, 431, 440, 442, 443, 454, 457, 458,
                       462, 471, 478, 481, 487, 489, 492, 499, 501, 502, 503,
                       506, 514, 524, 532, 535, 541, 550, 552, 557, 559, 562,
                       563, 567, 570, 571, 580, 592, 597, 604, 612};
const ull rmod = 0x1fffffffffffffff;
const ull base = bases[chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count() & 63];
const ull mask30 = (1UL << 30) - 1, mask31 = (1UL << 31) - 1;
struct RollingHash {
    vector<ull> hash, pow;
    inline ull mul(const ull &a, const ull &b) const {
        ull mid = (a & mask31) * (b >> 31) + (a >> 31) * (b & mask31);
        ull res = (a >> 31) * (b >> 31) * 2 + (mid >> 30) + ((mid & mask30) << 31);
        res += (a & mask31) * (b & mask31);
        res = (res >> 61) + (res & rmod);
        if (res >= rmod) res -= rmod;
        return res;
    }
    RollingHash(const string &s) {
        hash.resize(s.length() + 1);
        pow.resize(s.length() + 1);
        pow[0] = 1;
        for (int i = 0; i < s.length(); i++) {
            hash[i + 1] = mul(hash[i], base) + s[i];
            pow[i + 1] = mul(pow[i], base);
            if (hash[i + 1] >= rmod) hash[i + 1] -= rmod;
        }
    }
    ull get(int l, int r) { //[l,r]
        ull res = hash[r + 1] + rmod - mul(hash[l], pow[r + 1 - l]);
        if (res >= rmod) res -= rmod;
        return res;
    }
};
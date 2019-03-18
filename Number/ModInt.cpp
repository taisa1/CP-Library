template <ll mod>
struct modint {
    ll val;
    modint() : val(0) {}
    modint mpow(ll n) const {
        ll x = val;
        ll ret = 1;
        while(n > 0) {
            if(n & 1) ret = ret * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return ret;
    }
    template <class T>
    explicit operator T() {
        return T(val);
    }
    modint tomod(const T& to) const {
        modint m;
        m.val = to;
        return m;
    }
    modint operator+(const modint& to) const {
        return tomod((val + to.val % mod) % mod);
    }
    modint operator-(const modint& to) const {
        return tomod((val - to.val % mod + mod) % mod);
    }
    modint operator*(const modint& to) const {
        return tomod((val * to.val % mod) % mod);
    }
    modint operator/(const modint& to) const {
        return tomod((val * to.mpow(mod - 2)) % mod);
    }
    modint operator-() const { return tomod((mod - val + mod) % mod); }
    modint operator++() const { return tomod((val + 1) % mod); }
    modint operator--() const { return tomod((val - 1 + mod) % mod); }
    modint& operator+=(const modint& to) { return *this = *this + to; }
    modint& operator-=(const modint& to) { return *this = *this - to; }
    modint& operator*=(const modint& to) { return *this = *this * to; }
    modint& operator/=(const modint& to) { return *this = *this / to; }
    bool operator==(const modint& to) const { return val == to.val; }
    bool operator!=(const modint& to) const { return val != to.val; }
    bool operator>(const modint& to) const { return val > to.val; }
    bool operator>=(const modint& to) const { return val >= to.val; }
    bool operator<(const modint& to) const { return val < to.val; }
    bool operator<=(const modint& to) const { return val <= to.val; }
};
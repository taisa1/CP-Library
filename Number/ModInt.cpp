template <ll mod>
struct modint {
    ll val;
    inline ll extgcd(ll a, ll b, ll& x, ll& y) {
        if(b == 0) {
            x = 1, y = 0;
            return a;
        }
        ll d = extgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    inline ll minv(ll k) {
        ll x = 0, y = 0;
        extgcd(k, mod, x, y);
        if(x < 0) {
            x += mod;
        } else if(x == mod) {
            x = 0;
        }
        return x;
    }
    inline ll mpow(ll n) {
        ll res = 1, x = val;
        while(n > 0) {
            if(n & 1) {
                res *= x;
                res % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
    constexpr modint() : val(0) {}
    constexpr modint(ll x) { val = (x + mod) % mod; }
    modint inv() { return modint(minv(val)); }
    modint operator+(const modint& to) const { return modint(val + to.val); }
    modint operator-(const modint& to) const { return modint(val - to.val); }
    modint operator*(const modint& to) const { return modint(val * to.val); }
    modint operator/(const modint& to) const {
        return modint(val * minv(to.val));
    }
    template <class T>
    explicit operator T() {
        return T(val);
    }
    template <typename T>
    modint operator+(const T& to) const {
        return modint(val + to);
    }
    template <typename T>
    modint operator-(const T& to) const {
        return modint(val - to);
    }
    template <typename T>
    modint operator*(const T& to) const {
        return modint(val * to);
    }
    template <typename T>
    modint operator/(const T& to) const {
        return modint(val * minv(to));
    }
    modint& operator++() { return *this = modint(val + 1); }
    modint& operator--() { return *this = modint(val - 1); }
    template <typename T>
    modint& operator+=(const T& to) {
        return *this = *this + to;
    }
    template <typename T>
    modint& operator-=(const T& to) {
        return *this = *this - to;
    }
    template <typename T>
    modint& operator*=(const T& to) {
        return *this = *this * to;
    }
    template <typename T>
    modint& operator/=(const T& to) {
        return *this = *this / to;
    }
    bool operator==(const modint& to) const { return val == to.val; }
    bool operator!=(const modint& to) const { return val != to.val; }
    bool operator>(const modint& to) const { return val > to.val; }
    bool operator>=(const modint& to) const { return val >= to.val; }
    bool operator<(const modint& to) const { return val < to.val; }
    bool operator<=(const modint& to) const { return val <= to.val; }
};
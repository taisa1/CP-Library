class modint {
    using u64 = std::uint_fast64_t;
    static u64 &mod() {
        static u64 mod_ = 0;
        return mod_;
    }

  public:
    u64 a;
    modint(const u64 x = 0) noexcept : a(x % getmod()) {}
    u64 &value() noexcept { return a; }
    modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    modint operator^(const u64 rhs) const noexcept {
        return modint(*this) ^= rhs;
    }
    modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= getmod()) {
            a -= getmod();
        }
        return *this;
    }
    modint &operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
            a += getmod();
        }
        a -= rhs.a;
        return *this;
    }
    modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % getmod();
        return *this;
    }
    modint &operator/=(modint rhs) noexcept {
        u64 exp = getmod() - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    modint &operator^=(u64 exp) {
        modint rhs = modint(*this);
        a = 1;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    static void setmod(const u64 x) { mod() = x; }
    static u64 getmod() { return mod(); }
    friend ostream &operator<<(ostream &os, const modint &x) {
        os << x.a;
        return os;
    }
    friend istream &operator>>(istream &is, modint &x) {
        is >> x.a;
        return is;
    }
};
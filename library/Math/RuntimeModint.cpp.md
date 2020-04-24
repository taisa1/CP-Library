---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: Math/RuntimeModint.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/RuntimeModint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-24 17:48:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/RuntimeModint.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


template <class U>
struct RangeMin {
    using T = U;
    static T op(const T& a, const T& b) { return min(a, b); }
    static constexpr T id() { return inf; }
};

template <class U>
struct RangeMax {
    using T = U;
    static T op(const T& a, const T& b) { return max(a, b); }
    static constexpr T id() { return -inf; }
};

template <class U>
struct RangeSum {
    using T = U;
    static T op(const T& a, const T& b) { return a + b; }
    static constexpr T id() { return 0; }
};


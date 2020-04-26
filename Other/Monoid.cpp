//segtree(example:RMQ)
struct T {
    ll x;
    T() {}
    T(ll x) : x(x) {}
    inline static T id() {
        return 1LL << 60;
    }
    inline static T f(const T &x, const T &y) {
        return T(min(x.x, y.x));
    }
    inline static T g(const T &a, const T &b) {
        return b;
    }
};
//lazy segtree(example:RAQ+RMQ)
struct E {
    ll x;
    E() {}
    E(ll x) : x(x) {}
    inline static E id() {
        return E(0);
    }
    inline static E f(const E &x, const E &y) {
        return E(x + y);
    }
};
struct T {
    ll x;
    T() {}
    T(ll x) : x(x) {}
    inline static T id() {
        return 1LL << 60;
    }
    inline static T f(const T &x, const T &y) {
        return min(x.x, y.x);
    }
    inline static T g(const T &x, const E &y, const ll &len) {
        return x.x + y.x;
    }
};
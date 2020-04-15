template <class T>
struct SWAG {
    inline T f(const T &a, const T &b) {}
    T e;
    SWAG(const T &e) : e(e) {}
    stack<pair<T, T>> frontst, backst;
    void push(const T &x) {
        if (backst.empty()) {
            backst.emplace(x, x);
        } else {
            backst.emplace(x, f(backst.top().second, x));
        }
    }
    void pop() {
        if (frontst.empty()) {
            while (!backst.empty()) {
                if (frontst.empty()) {
                    frontst.emplace(backst.top().first, backst.top().first);
                } else {
                    frontst.emplace(backst.top().first, f(backst.top().first, frontst.top().second));
                }
                backst.pop();
            }
        }
        frontst.pop();
    }
    T fold() {
        if (frontst.empty() && backst.empty()) {
            return e;
        }
        if (frontst.empty()) {
            return backst.top().second;
        } else if (backst.empty()) {
            return frontst.top().second;
        }
        return f(frontst.top().second, backst.top().second);
    }
};
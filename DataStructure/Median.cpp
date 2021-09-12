//@docs Docs/Median.md
template <class T>
struct Med {
    multiset<T> lg;
    multiset<T, greater<T>> sm;
    void push(T x) {
        if (sm.empty()) {
            sm.insert(x);
            return;
        }
        T t = *sm.begin();
        if (sm.size() > lg.size()) {
            if (t <= x) {
                lg.insert(x);
            } else {
                lg.insert(t);
                sm.erase(sm.find(t));
                sm.insert(x);
            }
        } else {
            if (t >= x) {
                sm.insert(x);
            } else {
                lg.insert(x);
                sm.insert(*lg.begin());
                lg.erase(lg.begin());
            }
        }
    }
    void erase(T x) {
        if (sm.find(x) != sm.end()) {
            sm.erase(sm.find(x));
        } else {
            lg.erase(lg.find(x));
        }
        if (sm.size() > lg.size() + 1) {
            lg.insert(*sm.begin());
            sm.erase(sm.begin());
        }
        if (sm.size() < lg.size()) {
            sm.insert(*lg.begin());
            lg.erase(lg.begin());
        }
    }
    T get() {
        if (sm.size() == lg.size()) {
            return (*sm.begin() + *lg.begin()) / 2LL;
        } else {
            return *sm.begin();
        }
    }
};
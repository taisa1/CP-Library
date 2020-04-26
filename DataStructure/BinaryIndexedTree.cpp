//@docs Docs/BinaryIndexedTree.md
template <class T>
struct BinaryIndexedTree {
    int n;
    vector<T> dat;
    BinaryIndexedTree(const int &n) : n(n + 1), dat(n + 1) {}
    void add(int k, const T &x) {
        for (++k; k < n; k += k & -k) dat[k] += x;
    }
    T get(int k) {
        T res = 0;
        for (++k; k > 0; k -= k & -k) res += dat[k];
        return res;
    }
    inline T get(const int &l, const int &r) { //0-indexed [l,r)
        return get(r - 1) - get(l - 1);
    }
};
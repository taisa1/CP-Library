template <typename T>
struct ConvexHullTrick {  //単調性仮定CHT
    using L = pair<T, T>;
    vector<L> lines;
    ConvexHullTrick() {}
    bool check(L l1, L l2, L l3) {
        if(l1 < l3) swap(l1, l3);
        return (l2.first - l3.first) * (l2.second - l1.second) >=
               (l1.first - l2.first) * (l3.second - l2.second);
    }
    void add(T a, T b) {
        L line = make_pair(a, b);
        while(lines.size() >= 2 &&
              check(lines[lines.size() - 2], lines.back(), line))
            lines.pop_back();
        lines.push_back(line);
    }
    T f(L line, T x) { return line.first * x + line.second; }
    T query(T x) {
        int ng = -1, ok = lines.size() - 1;
        while(ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if(f(lines[mid], x) < f(lines[mid + 1], x)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return f(lines[ok], x);
    }
};
auto calc = [&](auto x) {
    return 0;
};
//整数値での三分探索
auto TernarySearch = [&](auto lb, auto ub) { //[lb,ub]
    using T = decltype(lb);
    T ok = lb - 1, ng = ub;
    while (ng - ok > 1) {
        T mid = (ok + ng) / 2;
        if (calc(mid + 1) - calc(mid) < 0) { //上に凸なら>
            ok = mid;
        } else {
            ng = mid;
        }
    }
};
struct IntervalSet : map<ll, ll> {
    void insert(ll l, ll r) {
        auto itl = upper_bound(l), itr = upper_bound(r + 1);
        if (itl != begin()) {
            --itl;
            if (itl->second < l) {
                ++itl;
            }
        }
        if (itl != itr) {
            l = min(l, itl->first);
            r = max(r, prev(itr)->second);
            erase(itl, itr);
        }
        (*this)[l] = r;
    }
};
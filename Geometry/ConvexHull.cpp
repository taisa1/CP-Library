//https://onlinejudge.u-aizu.ac.jp/status/users/TAISA_/submissions/1/CGL_4_A/judge/4344751/C++14
struct ConvexHull : vector<Point> {
    vector<Point> pt;
    ConvexHull(const vector<Point> &pt) : pt(pt) {}
    void build() {
        auto cmp = [](const Point &a, const Point &b) {
            return a.imag() == b.imag() ? a.real() < b.real() : a.imag() < b.imag();
        };
        sort(pt.begin(), pt.end(), cmp);
        for (int i = 0; i < pt.size(); i++) {
            while (size() > 1 && ccw((*this)[size() - 2], back(), pt[i]) <= 0) {
                pop_back();
            }
            emplace_back(pt[i]);
        }
        int lim = size();
        for (int i = (int)pt.size() - 2; i >= 0; i--) {
            while (size() > lim && ccw((*this)[size() - 2], back(), pt[i]) <= 0) {
                pop_back();
            }
            emplace_back(pt[i]);
        }
        pop_back();
    }
};
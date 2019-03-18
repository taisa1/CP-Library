using P = Points;
struct ConvexHull {
    vector<P> pts, in;
    int n;
    ConvexHull(vector<P> in) : in(in) {
        pts.resize(2 * in.size());
        build();
    }
    void build() {
        sort(in.begin(), in.end());
        int k = 0;
        for(int i = 0; i < in.size(); i++) {
            while(k > 1 &&
                  (pts[k - 1] - pts[k - 2]).det(in[i] - pts[k - 1]) <= 0)
                --k;
            pts[k++] = in[i];
        }
        for(int i = in.size() - 2, t = k; i >= 0; i--) {
            while(k > t &&
                  (pts[k - 1] - pts[k - 2]).det(in[i] - pts[k - 1]) <= 0)
                --k;
            pts[k++] = in[i];
        }
        pts.resize(k - 1);
        n = k - 1;
    }
};

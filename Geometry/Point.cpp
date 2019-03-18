struct Point {
    long double x, y;
    int idx;
    Point() {}
    Point(long double x, long double y) : x(x), y(y) {}
    long double add(long double a, long double b) {
        if(abs(a + b) < eps * (abs(a) + abs(b))) return 0;
        return a + b;
    }
    Point operator+(const Point& p) { return Point(add(x, p.x), add(y, p.y)); }
    Point operator-(const Point& p) {
        return Point(add(x, -p.x), add(y, -p.y));
    }
    Point operator*(const long double& d) { return Point(x * d, y * d); }
    bool operator<(const Point& p) const {
        return abs(x - p.x) > eps ? (x < p.x - eps) : (y < p.y - eps);
    }
    bool operator==(const Point& p) const {
        return abs(x - p.x) < eps && abs(y - p.y) < eps;
    }
    long double dot(const Point& p) { return add(x * p.x, y * p.y); }
    long double det(const Point& p) { return add(x * p.y, -y * p.x); }
};
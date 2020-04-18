---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: Geometry/Base.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d9c6333623e6357515fcbf17be806273">Geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/Geometry/Base.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 21:47:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
using D = double;
using Point = complex<D>;
const D eps = 1e-40;
inline int sgn(const D &a) { return (a < -eps) ? -1 : (a > eps) ? 1 : 0; }
inline D cross(const Point &a, const Point &b) {
    return a.real() * b.imag() - a.imag() * b.real();
}
inline D dot(const Point &a, const Point &b) {
    return a.real() * b.real() + a.imag() * b.imag();
}
istream &operator>>(istream &is, Point &p) {
    D a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
}
inline int ccw(const Point &a, const Point &b, const Point &c) {
    D d = cross(b - a, c - a);
    if (sgn(d) > 0) {
        return +1; //counter-clockwise
    } else if (sgn(d) < 0) {
        return -1; //clockwise
    } else {
        if (sgn(dot(b - a, c - a)) < 0) {
            return -2; //c,a,b
        } else if (sgn(dot(a - b, c - b)) < 0) {
            return +2; //a,b,c
        }
    }
    return 0; //a,c,b
}
struct Line {
    Point a, b; //a,bを通る直線
    Line(const Point &p0, const Point &p1) : a(p0), b(p1) {}
    Line(const Segment &s) : a(s.a), b(s.b) {}
};
struct Segment {
    Point a, b;
    Segment(const Point &p0, const Point &p1) : a(p0), b(p1) {}
};
inline Point projection(const Line &l, const Point &b) { //a to b
    return l.a + (dot(l.b - l.a, b - l.a) / norm(l.b - l.a)) * l.b;
}
inline Point reflection(const Line &l, const Point &b) {
    return b + (projection(l, b) - b) * static_cast<D>(2.0);
}
inline bool parallel(const Line &l1, const Line &l2) {
    return sgn(cross(l1.b - l1.a, l2.b - l2.a)) == 0;
}
inline bool vertical(const Line &l1, const Line &l2) {
    return sgn(dot(l1.b - l1.a, l2.b - l2.a)) == 0;
}
inline bool intersect(const Segment &s1, const Segment &s2) {
    return ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 && ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0;
} /*
Point crosspoint(const Line &l1, const Line &l2) {
    
}
inline Point crosspoint(const Segment &s1, const Segment &s2) {
    return crosspoint(Line(s1), Line(s2));
}*/
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Geometry/Base.cpp"
using D = double;
using Point = complex<D>;
const D eps = 1e-40;
inline int sgn(const D &a) { return (a < -eps) ? -1 : (a > eps) ? 1 : 0; }
inline D cross(const Point &a, const Point &b) {
    return a.real() * b.imag() - a.imag() * b.real();
}
inline D dot(const Point &a, const Point &b) {
    return a.real() * b.real() + a.imag() * b.imag();
}
istream &operator>>(istream &is, Point &p) {
    D a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
}
inline int ccw(const Point &a, const Point &b, const Point &c) {
    D d = cross(b - a, c - a);
    if (sgn(d) > 0) {
        return +1; //counter-clockwise
    } else if (sgn(d) < 0) {
        return -1; //clockwise
    } else {
        if (sgn(dot(b - a, c - a)) < 0) {
            return -2; //c,a,b
        } else if (sgn(dot(a - b, c - b)) < 0) {
            return +2; //a,b,c
        }
    }
    return 0; //a,c,b
}
struct Line {
    Point a, b; //a,bを通る直線
    Line(const Point &p0, const Point &p1) : a(p0), b(p1) {}
    Line(const Segment &s) : a(s.a), b(s.b) {}
};
struct Segment {
    Point a, b;
    Segment(const Point &p0, const Point &p1) : a(p0), b(p1) {}
};
inline Point projection(const Line &l, const Point &b) { //a to b
    return l.a + (dot(l.b - l.a, b - l.a) / norm(l.b - l.a)) * l.b;
}
inline Point reflection(const Line &l, const Point &b) {
    return b + (projection(l, b) - b) * static_cast<D>(2.0);
}
inline bool parallel(const Line &l1, const Line &l2) {
    return sgn(cross(l1.b - l1.a, l2.b - l2.a)) == 0;
}
inline bool vertical(const Line &l1, const Line &l2) {
    return sgn(dot(l1.b - l1.a, l2.b - l2.a)) == 0;
}
inline bool intersect(const Segment &s1, const Segment &s2) {
    return ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 && ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0;
} /*
Point crosspoint(const Line &l1, const Line &l2) {
    
}
inline Point crosspoint(const Segment &s1, const Segment &s2) {
    return crosspoint(Line(s1), Line(s2));
}*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


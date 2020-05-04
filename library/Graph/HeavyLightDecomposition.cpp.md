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


# :heavy_check_mark: Graph/HeavyLightDecomposition.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/HeavyLightDecomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 12:58:11+09:00




## Description
木を HL 分解する。  
addedge(u,v) : 木に辺 (u,v) を追加する。 N-1 辺追加した時点で自動で build() を呼び、HL分解を行う。    
getpath(u,v,f) : (u,v) パス上の全頂点について、関数 f を適用する。   
getsubtree(u) : u の部分木内の全頂点について、関数 f を適用する。  
index(i) : i のHL分解後の index を返す。  

## Verified with

* :heavy_check_mark: <a href="../../verify/Test/HLDpath.test.cpp.html">Test/HLDpath.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Test/HLDsubtree.test.cpp.html">Test/HLDsubtree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//@docs Docs/HeavyLightDecomposition.md
struct HLD {
    int n;
    vector<vector<int>> G;
    vector<int> sz, rt, id, par, out;
    int pos, cnt;
    HLD(int n) : n(n), G(n), sz(n, 1), rt(n, -1), id(n), par(n, -1), out(n), cnt(0) {}
    void addedge(const int &u, const int &v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        cnt++;
        if (cnt == n - 1) {
            build();
        }
    }
    void build() {
        szdfs(0, -1);
        id[0] = 0;
        rt[0] = 0;
        pos = 0;
        hld(0, -1);
    }
    void szdfs(int i, int p) {
        for (auto &e : G[i]) {
            if (e == p) continue;
            szdfs(e, i);
            par[e] = i;
            sz[i] += sz[e];
            if (sz[e] > sz[G[i][0]]) {
                swap(G[i][0], e);
            }
        }
    }
    void hld(int i, int p) {
        id[i] = pos;
        pos++;
        for (auto &e : G[i]) {
            if (e == p) continue;
            if (e == G[i][0]) {
                rt[e] = rt[i];
            } else {
                rt[e] = e;
            }
            hld(e, i);
        }
        out[i] = pos;
    }
    template <class F>
    void getpath_v(int u, int v, const F &f) { //f:[a,b)
        while (1) {
            if (id[u] > id[v]) swap(u, v);
            if (rt[u] == rt[v]) {
                f(id[u], id[v] + 1);
                break;
            } else {
                f(id[rt[v]], id[v] + 1);
                v = par[rt[v]];
            }
        }
    }
    template <class F>
    void getpath_e(int u, int v, const F &f) { //f:[a,b)
        while (1) {
            if (id[u] > id[v]) swap(u, v);
            if (rt[u] == rt[v]) {
                if (u != v) f(id[u] + 1, id[v] + 1);
                break;
            } else {
                f(id[rt[v]], id[v] + 1);
                v = par[rt[v]];
            }
        }
    }
    template <class F>
    void getsubtree(const int &u, const F &f) { //f:[a,b)
        f(id[u], out[u]);
    }
    inline int index(const int &i) {
        return id[i];
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/HeavyLightDecomposition.cpp"
//@docs Docs/HeavyLightDecomposition.md
struct HLD {
    int n;
    vector<vector<int>> G;
    vector<int> sz, rt, id, par, out;
    int pos, cnt;
    HLD(int n) : n(n), G(n), sz(n, 1), rt(n, -1), id(n), par(n, -1), out(n), cnt(0) {}
    void addedge(const int &u, const int &v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        cnt++;
        if (cnt == n - 1) {
            build();
        }
    }
    void build() {
        szdfs(0, -1);
        id[0] = 0;
        rt[0] = 0;
        pos = 0;
        hld(0, -1);
    }
    void szdfs(int i, int p) {
        for (auto &e : G[i]) {
            if (e == p) continue;
            szdfs(e, i);
            par[e] = i;
            sz[i] += sz[e];
            if (sz[e] > sz[G[i][0]]) {
                swap(G[i][0], e);
            }
        }
    }
    void hld(int i, int p) {
        id[i] = pos;
        pos++;
        for (auto &e : G[i]) {
            if (e == p) continue;
            if (e == G[i][0]) {
                rt[e] = rt[i];
            } else {
                rt[e] = e;
            }
            hld(e, i);
        }
        out[i] = pos;
    }
    template <class F>
    void getpath_v(int u, int v, const F &f) { //f:[a,b)
        while (1) {
            if (id[u] > id[v]) swap(u, v);
            if (rt[u] == rt[v]) {
                f(id[u], id[v] + 1);
                break;
            } else {
                f(id[rt[v]], id[v] + 1);
                v = par[rt[v]];
            }
        }
    }
    template <class F>
    void getpath_e(int u, int v, const F &f) { //f:[a,b)
        while (1) {
            if (id[u] > id[v]) swap(u, v);
            if (rt[u] == rt[v]) {
                if (u != v) f(id[u] + 1, id[v] + 1);
                break;
            } else {
                f(id[rt[v]], id[v] + 1);
                v = par[rt[v]];
            }
        }
    }
    template <class F>
    void getsubtree(const int &u, const F &f) { //f:[a,b)
        f(id[u], out[u]);
    }
    inline int index(const int &i) {
        return id[i];
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


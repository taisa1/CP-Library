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


# :warning: Graph/HeavyLightDecomposition.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/HeavyLightDecomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-15 13:25:24+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//Path Sum and Subtree Sum
struct HLD {
    int n;
    vector<vector<int>> G;
    vector<int> sz, rt, id, par, out;
    int pos;
    HLD(int n) : n(n), G(n), sz(n, 1), rt(n, -1), id(n), par(n, -1), out(n) {}
    void addedge(int u, int v) {
        G[u].eb(v);
        G[v].eb(u);
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
    inline ll f(int a, int b) { return 0; } //[a,b]
    ll get_v(int u, int v) {
        ll res = 0;
        while (1) {
            if (id[u] > id[v]) swap(u, v);
            if (rt[u] == rt[v]) {
                res += f(id[u], id[v]);
                break;
            } else {
                res += f(id[rt[v]], id[v]);
                v = par[rt[v]];
            }
        }
        return res;
    }
    ll subtree(int u) {
        return f(id[u], out[u]);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/HeavyLightDecomposition.cpp"
//Path Sum and Subtree Sum
struct HLD {
    int n;
    vector<vector<int>> G;
    vector<int> sz, rt, id, par, out;
    int pos;
    HLD(int n) : n(n), G(n), sz(n, 1), rt(n, -1), id(n), par(n, -1), out(n) {}
    void addedge(int u, int v) {
        G[u].eb(v);
        G[v].eb(u);
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
    inline ll f(int a, int b) { return 0; } //[a,b]
    ll get_v(int u, int v) {
        ll res = 0;
        while (1) {
            if (id[u] > id[v]) swap(u, v);
            if (rt[u] == rt[v]) {
                res += f(id[u], id[v]);
                break;
            } else {
                res += f(id[rt[v]], id[v]);
                v = par[rt[v]];
            }
        }
        return res;
    }
    ll subtree(int u) {
        return f(id[u], out[u]);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


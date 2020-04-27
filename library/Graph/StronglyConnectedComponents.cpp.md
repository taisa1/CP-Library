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


# :heavy_check_mark: Graph/StronglyConnectedComponents.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/StronglyConnectedComponents.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 12:42:37+09:00




## Description
グラフ G の強連結成分を管理する。  
addedge(u,v) : G に有向辺 (u,v) を追加する。  
scc() : G を強連結成分分解する。  
cmp[i] : i の属する強連結成分の index  
bl[i] : i 番目の強連結成分に含まれる要素の集合  

## Verified with

* :heavy_check_mark: <a href="../../verify/Test/SCC.test.cpp.html">Test/SCC.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//@docs Docs/StronglyConnectedComponents.md
struct SCC {
    int n;
    vector<int> ord, vis, cm;
    vector<vector<int>> bl, G, rG;
    SCC(int n) : n(n), bl(n), G(n), rG(n), cm(n), vis(n) {}
    void addedge(int u, int v) {
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    void dfs(int i) {
        vis[i] = 1;
        for (auto &e : G[i]) {
            if (vis[e]) continue;
            dfs(e);
        }
        ord.eb(i);
    }
    void rdfs(int i, int c) {
        vis[i] = 1;
        bl[c].emplace_back(i);
        cm[i] = c;
        for (auto &e : rG[i]) {
            if (vis[e]) continue;
            rdfs(e, c);
        }
    }
    //強連結成分分解し、成分数を返す bl[i]:i番目の成分に属する頂点集合、cm[i]:頂点iの成分
    //成分はトポロジカル順に並ぶ
    int scc() {
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i);
        }
        reverse(ord.begin(), ord.end());
        vis.assign(n, 0);
        int k = 0;
        for (auto &e : ord) {
            if (!vis[e]) {
                bl.emplace_back(vector<int>());
                rdfs(e, k);
                k++;
            }
        }
        return k;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/StronglyConnectedComponents.cpp"
//@docs Docs/StronglyConnectedComponents.md
struct SCC {
    int n;
    vector<int> ord, vis, cm;
    vector<vector<int>> bl, G, rG;
    SCC(int n) : n(n), bl(n), G(n), rG(n), cm(n), vis(n) {}
    void addedge(int u, int v) {
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    void dfs(int i) {
        vis[i] = 1;
        for (auto &e : G[i]) {
            if (vis[e]) continue;
            dfs(e);
        }
        ord.eb(i);
    }
    void rdfs(int i, int c) {
        vis[i] = 1;
        bl[c].emplace_back(i);
        cm[i] = c;
        for (auto &e : rG[i]) {
            if (vis[e]) continue;
            rdfs(e, c);
        }
    }
    //強連結成分分解し、成分数を返す bl[i]:i番目の成分に属する頂点集合、cm[i]:頂点iの成分
    //成分はトポロジカル順に並ぶ
    int scc() {
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i);
        }
        reverse(ord.begin(), ord.end());
        vis.assign(n, 0);
        int k = 0;
        for (auto &e : ord) {
            if (!vis[e]) {
                bl.emplace_back(vector<int>());
                rdfs(e, k);
                k++;
            }
        }
        return k;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


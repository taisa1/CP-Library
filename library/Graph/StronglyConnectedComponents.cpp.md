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


# :warning: Graph/StronglyConnectedComponents.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/StronglyConnectedComponents.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-15 13:25:24+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<vector<int>> G;
struct SCC {
    int n;
    vector<int> ord, vis, cm;
    vector<vector<int>> bl, rG;
    SCC(int n) : n(n), bl(n), rG(n), cm(n) {}
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
        bl[c].eb(i);
        cm[i] = c;
        for (auto &e : rG[i]) {
            if (vis[e]) continue;
            rdfs(e, c);
        }
    }
    void build() {
        for (int i = 0; i < n; i++) {
            for (auto &e : G[i]) {
                rG[e].eb(i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i);
        }
        reverse(all(ord));
        vis.assign(n, 0);
        int k = 0;
        for (auto &e : ord) {
            if (!vis[e]) {
                bl.eb(vector<int>());
                rdfs(e, k);
                k++;
            }
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/StronglyConnectedComponents.cpp"
vector<vector<int>> G;
struct SCC {
    int n;
    vector<int> ord, vis, cm;
    vector<vector<int>> bl, rG;
    SCC(int n) : n(n), bl(n), rG(n), cm(n) {}
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
        bl[c].eb(i);
        cm[i] = c;
        for (auto &e : rG[i]) {
            if (vis[e]) continue;
            rdfs(e, c);
        }
    }
    void build() {
        for (int i = 0; i < n; i++) {
            for (auto &e : G[i]) {
                rG[e].eb(i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i);
        }
        reverse(all(ord));
        vis.assign(n, 0);
        int k = 0;
        for (auto &e : ord) {
            if (!vis[e]) {
                bl.eb(vector<int>());
                rdfs(e, k);
                k++;
            }
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


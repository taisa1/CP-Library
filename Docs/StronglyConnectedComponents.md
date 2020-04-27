## Description
グラフ G の強連結成分を管理する。  
addedge(u,v) : G に有向辺 (u,v) を追加する。  
scc() : G を強連結成分分解する。  
cmp[i] : i の属する強連結成分の index  
bl[i] : i 番目の強連結成分に含まれる要素の集合  
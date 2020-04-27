## Description
木を HL 分解する。  
addedge(u,v) : 木に辺 (u,v) を追加する。 N-1 辺追加した時点で自動で build() を呼び、HL分解を行う。    
getpath(u,v,f) : (u,v) パス上の全頂点について、関数 f を適用する。   
getsubtree(u) : u の部分木内の全頂点について、関数 f を適用する。  
index(i) : i のHL分解後の index を返す。  
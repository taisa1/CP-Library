## Description
モノイド列 A を二分木上で管理する。全て 0-indexed。  
setval(k,x) : A_k を x に変更する。  
upd(a,b,x) : [a,b) に x を作用させる。 O(log N)  
get(a,b) : [a,b) の演算結果を返す。 O(log N)  
find(a,b,x) : [a,b) において、値が x 以下であるような最も左の index を求める。 O(log N)  

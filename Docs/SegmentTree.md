## Description
モノイド列 A を管理する。全て 0-indexed。  
upd(k,x) : A_k に x を作用させる。 O(log N)   
get(a,b) : [a,b) の演算結果を返す。 O(log N)  
find(a,b,x) : [a,b) における、値が x 以下であるような最も左の index を返す。 O(log N)  
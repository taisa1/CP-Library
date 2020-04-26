## Description
数列の最小値を管理するデータ構造。0-indexed。  
build(a) : 数列 a から Sparse Table を作成する。 O(NlogN)  
get(l,r) : [l,r) における数列 a の最小値を求める。 O(1)  
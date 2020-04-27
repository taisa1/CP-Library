## Description
素集合を管理する部分永続データ構造。
find(x,t) : 時刻 t 終了時の x の root を求める。 O(log N)   
unite(u,v,t) : 時刻 t に u と v の属する集合を併合する。 O(log N)  
same(u,v,t) : 時刻 t 終了時に (u,v) が同じ集合に属するか判定する。  
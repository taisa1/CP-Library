## Description
素集合を管理する。  
find(x) : x の属する集合の root を返す。 O(1)  
unite(u,v) : u,v それぞれが属する集合を併合する。 償却 O(log N)  
size(x) : x の属する集合のサイズを返す。 O(1)  
same(u,v) : u,v が同じ集合に属するか判定する。 O(1)  
elements(u) : u を含む集合の vector を返す。 O(1)  

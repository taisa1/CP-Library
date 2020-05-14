## Description
素集合と要素のポテンシャル val を管理する。  
find(x) : x のポテンシャルを更新し、 x の属する集合の root を返す。 O(α(N))  
value(x) : x のポテンシャルを返す。O(α(N))  
unite(u,v,w) : u,v それぞれが属する集合を併合し、value(v) - value(u) = w の条件を満たすようにポテンシャルを更新する。 O(α(N))  
size(x) : x の属する集合のサイズを返す。 O(1)  
same(u,v) : u,v が同じ集合に属するか判定する。 O(α(N))  

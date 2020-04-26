## Description
集合を二分木上で管理する。  
各ノードにはキーと優先度を持ち、右ほどキーが大きく、上ほど優先度が大きい。  
pair を key とすることで、多重集合を表現できる。  
insert(x) : Treap に key=x なるノードを挿入する。  
erase(x) : Treap 内の key=x なるノードを全て削除する。  
count(x) : Treap 内の key=x なるノードの個数を返す。  
order_of_key(x) : Treap 内で、 key が x 未満のノードの個数を返す。  
find_by_order(x) : Treap 内で、 x 番目に大きい key を返す。  
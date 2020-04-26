## Description
モノイドを Treap 上で管理する。  
各ノードは、ある区間を表し、区間内の演算結果を持つ。    
eval(t) : ノード t について、ノードに持つ情報を再計算する。  
insert(x,m) : Treap に key=x,val=m なるノードを挿入する。  
erase(x) : Treap 内の key=x なるノードを全て削除する。  
count(x) : Treap 内の key=x なるノードの個数を返す。  
order_of_key(x) : Treap 内で、 key が x 未満のノードの個数を返す。  
find_by_order(x) : Treap 内で、 x 番目に大きい key を返す。  
get(l,r) : Treap内で、 key が [l,r) の範囲内であるノードについての演算結果を返す。

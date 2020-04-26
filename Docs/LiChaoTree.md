## Description
複数の直線 f(x)=ax+b を完全二分木上で管理し、Convex Hull Trick を行う。  
取得の際に与えられる x 座標が全て事前に分かっていないと使えないことに注意。 
N を与えられる x 座標の個数とする。 
preadd(x) : 与えられる x 座標 x を追加。 O(1)  
build() : Li Chao Tree を構築。 O(N log N)  
add(a,b) : f(x)=ax+b を追加する。 O(log N)  
get(x) : 全ての直線についての、 f(x) の最小値を返す。 O(log N)  

template<typename T>
struct RBST{
    struct Node{
        T val;
        Node* l,r;
        size_t size;
        Node(T val):val(val),size(1){
            r=l=nullptr;
        }
    };
    size_t size(Node* node){
        if(!node)return 0;
        return node->size;
    }
    void update(Node* node){
        node->size=size(node->l)+size(node->r)+1;
    }
    Node* find(Node* node,T val){
        if(!node)return nullptr;
        if(val==node->val)return node;
        if(val<node->val){
            return find(node->l,val);
        }else{
            return find(node->r,val);
        }
    }
    Node* insert(Node* node,T val){
        if(!node)return new Node(val);
        if(node->val>val){
            node->l=insert(node->l,val);
        }else{
            node->r=insert(node->r,val);
        }
        update(node);
    }

}
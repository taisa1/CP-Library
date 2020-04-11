template <class T, int LOG>
struct BinaryTrie {
    struct Node {
        bool a;
        Node *to[2];
        Node(bool a) : a(a) { to[0] = to[1] = nullptr; }
    };
    Node *root;
    BinaryTrie() {
        root = new Node(0);
    }
    void insert(T x) {
        Node *now = root;
        for (int i = LOG - 1; i >= 0; i--) {
            if (now->to[(x >> i) & 1LL] == nullptr) {
                now->to[(x >> i) & 1LL] = new Node((x >> i) & 1LL);
            }
            now = now->to[(x >> i) & 1LL];
        }
    }
    void erase(ll x) {
        Node *now = root;
        for (int i = 0; i < LOG; i++) {
            now = now->to[(x >> (LOG - i)) & 1LL];
            now->cnt--;
        }
    }
    T min_element() {
        Node *now = root;
        for (int i = 0; i < LOG; i++) {
            if (!now->to[0] || now->to[0]->cnt > 0) {
                now = now->to[0];
            } else {
                now = now->to[1];
            }
        }
    }
    T max_element() {
        Node *now = root;
        for (int i = 0; i < LOG; i++) {
            if (!now->to[1] || now->to[1]->cnt > 0) {
                now = now->to[1];
            } else {
                now = now->to[0];
            }
        }
    }
};
template <int charsiz>
struct Node {
    char c;
    Node *to[charsiz];
    Node(char c) : c(c) {
        for (int i = 0; i < charsiz; i++) {
            to[i] = nullptr;
        }
    }
};
template <int charsiz>
struct Trie {
    Node<charsiz> *root;
    Trie() {
        root = new Node<charsiz>('?');
    }
    inline int index(const char &c) { return c - 'a'; }
    Node<charsiz> *insert(const string &s) {
        Node<charsiz> *now = root;
        for (int i = 0; i < s.length(); i++) {
            now = now->to[index(s[i])];
            if (now == nullptr) {
                now = new Node<charsiz>(s[i]);
            }
        }
        return now;
    }
};
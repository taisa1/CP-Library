//@docs Docs/FastMoebiusTransform.md
template <class T>
void fmt(vector<T> &a, bool up) {
    int n = a.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                if (up) {
                    a[j] -= a[j | i];
                } else {
                    a[j | i] -= a[j];
                }
            }
        }
    }
}
//@docs Docs/MP.md
vector<int> MP(string &s) {
    int j = -1;
    int n = s.length();
    vector<int> a(n + 1);
    a[0] = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) {
            j = a[j];
        }
        j++;
        a[i + 1] = j;
    }
    return a;
}
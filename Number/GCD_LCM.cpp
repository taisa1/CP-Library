constexpr ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    ll r = a % b;
    while(r) a = b, b = r, r = a % b;
    return b;
}

ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll extgcd(ll a, ll b, ll& x, ll& y) {
    if(b == 0) {
        x = 1, y = 0;
        return;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

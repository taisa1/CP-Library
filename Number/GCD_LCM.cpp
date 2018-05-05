ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    ll r=a%b;
    while(r)a=b,b=r,r=a%b;
    return b;
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
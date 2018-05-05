ll digitsum(ll n){
    ll sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int digits(ll n){
    int dig=0; 
    while(n>0){
        n/=10;
        dig++;
    }
    return dig;
}

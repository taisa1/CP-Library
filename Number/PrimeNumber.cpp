vector<bool> eratosthenes(int n){
    vector<bool> prime(n,true);
    prime[0]=false;prime[1]=false;
    for(int i=2;i<=n;i++){
        if(prime[i]){
            for(int j=i*2;j<=n;j+=i){
                prime[j]=false;
            }
        }
    }
    return prime;
}

bool isprime(int n){
    for(int i=0;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
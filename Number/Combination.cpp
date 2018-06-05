ll f[2000010],fi[2000010];
ll mod_pow(ll x,ll n,ll mod){
    ll ret=1;
    while(n>0){
        if(n&1){
            ret=ret*x%mod;
        }
        x=x*x%mod;
        n>>=1;
    }
    return ret;
}

void fact(ll n){
	f[0]=1;
	for(ll i=1;i<=n;i++){
		f[i]=f[i-1]*i%MOD;
	}
	fi[n]=mod_pow(f[n],MOD-2,MOD);
	for(ll i=n-1;i>=0;i--){		
		fi[i]=fi[i+1]*(i+1)%MOD;
	}
}

ll nck(ll n,ll k){
	if(n<k)return 0;
	if(k==0){
		return 1;
	}else{
		return f[n]*fi[k]%MOD*fi[n-k]%MOD;
	}
}

ll hck(ll n,ll k){
	if(n==0&&k==0)return 1;
    return f[n+k-1]*fi[k]%MOD*fi[n-1]%MOD;   
}
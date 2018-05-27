ll mod_pow(ll x,ll p,ll mod){
	if(p==0)return 1;
	ll res=mod_pow((x*x)%mod,p/2,mod);
	if(p%2)(res*=x)%=mod;
	return res;
}

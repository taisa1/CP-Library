using long long=ll;
using mint=modint<ll,MOD>;
void fact(int n,vector<mint>& f,vector<mint>& fi){
	f.resize(n+1);
	fi.resize(n+1);
	f[0]=1;
	for(mint i=1;i<=n;i++)f[i]=f[i-1]*i;
	fi[n]=f[n].mpow(MOD-2);
	for(mint i=n-1;i>=0;i--)fi[i]=fi[i+1]*(i+1);
}
mint ncr(mint n,mint r){
	if(n<r)return 0;
	if(r==0){
		return 1;
	}else{
		return f[n]*fi[k]*fi[n-k];
	}
}

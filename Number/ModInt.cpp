#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct modint{
    ll mod,val;
    modint(ll mod):mod(mod){val=0;};
    modint mpow(ll n) const{
        if(n==0)return 1;
        ll x=val,ret=1;
        while(n>1){
            if(n&1)ret=ret*x%mod;
            x=x*x%mod;
            n>>=1;
        }
        return ret;
    }
    modint operator+(const motint& to) const{
        return (val+to.val%mod)%mod;
    }
    modint operator-(const modint& to) const{
        return (val-to.val%mod+mod)%mod;
    }
    modint operator*(const modint& to) const{
        return (val*to.val%mod)%mod;
    }
    modint operator/(const modint& to) const{
        return (val*to.mpow(mod-2))%mod;
    }
    modint operator-() const{
        return (mod-val+mod)%mod;
    }
    modint operator++() const{
        return (val+1)%mod;
    }
    modint operator--() const{
        return (val-1+mod)%mod;
    }
    modint& operator+=(const modint& to){
        return  *this=*this+to;
    }
    modint& operator-=(const modint& to){
        return  *this=*this-to;
    }
    modint& operator*=(const modint& to){
        return  *this=*this*to;
    }
    modint& operator/=(const modint& to){
        return  *this=*this/to;
    }
    bool operator==(const modint& to){
        return val==to.val;
    }
    bool operator!=(const modint& to){
        return val!=to.val;
    }
    bool operator>(const modint& to){
        return val>to.val;
    }
    bool operator>=(const modint& to){
        return val>=to.val;
    }
    bool operator<(const modint& to){
        return val<to.val;
    }
    bool operator<=(const modint& to){
        return val<=to.val;
    }
};

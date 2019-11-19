#include<bits/stdc++.h>
 
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
 
#define pb push_back
#define popb pop_back
#define si size()
#define sof sizeof()
#define be begin()
#define en end()
#define all(v) v.be,v.en
#define le length()
#define mp make_pair 
#define mt make_tuple
#define F first
#define S second
#define ask(i,m,n) for(int i=m;i<n;i++)
 
#define deci(n)  fixed<<setprecision(n)
#define high(n) __builtin_popcount(n)
#define parity(n) __builtin_parity(n)
#define ctz(n)  __builtin_ctz(n)
#define maxe *max_element
#define mine *min_element
#define anket ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
 
#define endl "\n"
#define o0(a) cout<<a<<" "
#define o1(a) cout<<a<<"\n"
#define o2(a,b) cout<<a<<" "<<b<<"\n"
#define o3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define o4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"
using namespace std;

#define mod 1000000007

inline lli modadd(lli n,lli m){
    lli sum = ((n+m)%mod+mod)%mod;
    return sum;
}

inline lli modsub(lli n,lli m){
    lli diff = ((n-m+mod)%mod+mod)%mod;
    return diff;
}

inline lli modpro(lli n,lli m){
    lli pro = ((n*m)%mod+mod)%mod;
    return pro;
}



inline lli pow(int x,int y){
    lli res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}



inline lli powmod(lli x,lli y){
    lli res = 1;
    while (y > 0) {
        if (y & 1)
            res = modpro(res , x);
        y = y >> 1;
        x = modpro(x , x);
    }
    return res;
}


int main() {
	anket;
	lli t;
	cin>>t;
	ask(i,0,t){
	    lli n;
	    cin>>n;
	    lli a,b=0,c=0,d=0,e=0;
	    ask(j,0,n){
	        cin>>a;
	        if(a%2==0){
	            b++;
	        }
	        else{
	            c++;
	        }
	    }
	    lli m;
	    cin>>m;
	    ask(j,0,m){
	        cin>>a;
	        if(a%2==0){
	            d++;
	        }
	        else{
	            e++;
	        }
	    }
	    o1(b*d+c*e);
	}
	return 0;
}
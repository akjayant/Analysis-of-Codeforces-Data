#include<bits/stdc++.h>
#define ll long long
#define R register
using namespace std;
const ll mod = 1e9+7;
template <class Ruby_Rose> inline void read(Ruby_Rose &x)
{
 	x=0;
	char ch=getchar(), w=0;
	while(!isdigit(ch))w=(ch=='-'), ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	x=w?-x:x;
}
inline ll quickpow(ll base ,ll w)
{
	ll ans=1;
	while(w)
	{
		if(w&1)ans=ans*base%mod;
		base=base*base%mod, w>>=1;
	}
	return ans;
}
int main()
{
	ll n, m;
	read(n), read(m);
	cout<<quickpow(quickpow(2, m)-1, n);
	return 0;
}
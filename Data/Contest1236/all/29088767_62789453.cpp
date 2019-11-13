/***
 *      __  __            _    _       _
 *     |  \/  |          | |  | |     | |
 *     | \  / |_ __      | |  | |_ __ | | ___ __   _____      ___ __
 *     | |\/| | '__|     | |  | | '_ \| |/ / '_ \ / _ \ \ /\ / / '_ \
 *     | |  | | |     _  | |__| | | | |   <| | | | (_) \ V  V /| | | |
 *     |_|  |_|_|    (_)  \____/|_| |_|_|\_\_| |_|\___/ \_/\_/ |_| |_|
 *
 *
***/
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*---------------for_stuff-------------------*/
#define f(i,a,b) for (int i=a;i<=b;i++)
#define f_(i,a,b) for (int i=a;i>=b;i--)
/*---------------pair_stuff------------------*/
#define MP make_pair
#define ii pair<int,int>
#define Iii pair<int,ii>
#define ill pair<int,ll>
#define lli pair<ll,int>
#define iiI pair<ii,int>
#define llll pair<ll,ll>
#define fi first
#define se second
/*--------------vector_stuff-----------------*/
#define pb push_back
#define ppb pop_back
/*--------------const_stuff-----------------*/
const ll mod=1000000007;
/*--------------map_stuff--------------------*/
// why do you think I should write something in this part? :v

ll n,m,ans;
ll binpow(ll mu,ll cs) {
	if (mu==1) return cs;
	ll coso;
	coso=binpow(mu/2,cs);
	coso=coso*coso;
	coso%=mod;
	if (mu%2!=0) {
		coso*=cs;
		coso%=mod;
	}
	return coso;
}
signed main() {
	cin>>n>>m;
	ans=binpow(m,2ll);
	// cout<<m<<" ";
	ans--;
	// cout<<m<<" ";
	if (ans<0) ans+=mod;
	ans=binpow(n,ans);
	cout<<ans;
	return 0;
}
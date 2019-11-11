#include <bits/stdc++.h>
#define N 1000005
#define ll long long int 	
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define sp " "
#define endl "\n"
#define fi first
#define se second
#define ii pair<int,int>
#define lli pair<ll,ll>
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define fast2 freopen ("badhair.gir","r",stdin);freopen ("badhair.cik","w",stdout);
#define mod 1000000007
#define fs(x,y) for(ll i=1;i<=y;i++) cin>>x[i]
#define fo(i,x,y) for(ll i=x;i<=y;i++)
#define INF 1000000000005
using namespace std;

ll n,m,ar[N],sum,t,tut[N];

char s[N];

ll carp(ll a,ll b)
{
	a%=mod;
	b%=mod;
	// return (a*b)%mod;
	return ((a*b)%mod+mod)%mod;
}
ll add(ll a,ll b)
{
	a%=mod;
	b%=mod;
	return ((a+b)%mod+mod)%mod;
}

int main()
{
	fast;
	cin>>s+1;
	tut[0]=1;
	tut[1]=1;
	fo(i,2,1e5+2)
	tut[i]=add(tut[i-1],tut[i-2]);
	n=strlen(s+1);
	fo(i,1,n)
	if(s[i]=='w' || s[i]=='m')
		return cout<<0,0;
	sum=1;
	int a=0,b=0;
	// cout<<tut[2]<<endl;
	fo(i,1,n+1)
	{

		if(a && s[i]!='n')
			sum=carp(sum,tut[a]),a=0;
		if(b && s[i]!='u')
			sum=carp(tut[b],sum),b=0;
		if(s[i]=='n')
			a++;
		if(s[i]=='u')
			b++;
		// cout<<a<<sp<<b<<endl;
	}
	cout<<sum;

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/
		
#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long int
#define mem(x) memset(x,0,sizeof(x))
#define setbits(x)  __builtin_popcount(x)
#define ull unsigned long long int
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rep1(i,a,b)  for(int i=a;i<=b;i++)
#define fun(s,e,c) for(int i=s;i<e;i+=c)
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
using namespace std;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef pair<ll,int> li;
inline void fast()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
const int N=(int)(1e5)+5;
const ll mod=(ll)(1e9)+7;
int main()
{
	fast();
	ll n,m;
	cin>>n>>m;
	ll f[N];
	f[1]=2;
	f[2]=4;
	for(int i=3;i<N;i++)
	{
		f[i]=(f[i-1]+f[i-2])%mod;
		f[i]=f[i]%mod;
	}
	 ll ans=(f[n]%mod+(f[m]-f[1]+mod)%mod)%mod;
	 ans=ans%mod;
	 cout<<ans;





}
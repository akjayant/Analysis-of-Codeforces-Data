#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef __int128 LL;
//typedef unsigned long long ull;
//#define F first
//#define S second
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
const ld PI=acos(-1);
const ld eps=1e-9;
//unordered_map<int,int>mp;
/*int head[M],cnt;
struct EDGE{int to,nxt,val;}ee[M];
void add(int x,int y,int z){ee[++cnt].nxt=head[x],ee[cnt].to=y,ee[cnt].val=z,head[x]=cnt;}*/
#define ls (o<<1)
#define rs (o<<1|1)
#define pb push_back
const int seed=131;
const int M = 1e6+7;
ll p[M],c[M];
int pm;
void divide(ll n)
{
	pm=0;
	for(ll i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			p[++pm]=i,c[pm]=0;
			while(n%i==0)n/=i,c[pm]++;
		}
	}
	if(n>1)p[++pm]=n,c[pm]=1;//表示n是个质数 
//	for(int i=1;i<=pm;i++)
//	printf("%lld %lld\n",p[i],c[i]);
}
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	ll n;
  	cin>>n;
  	divide(n);
  	ll ans=1;
  	if(pm==1)
	{
		cout<<p[1];
	//	else cout<<c[1];
	}
	else cout<<1;
	cout<<endl;
	return 0;
}
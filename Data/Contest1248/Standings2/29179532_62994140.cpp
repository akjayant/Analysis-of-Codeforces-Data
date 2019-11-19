//Code of C#oder Born_Clear
#include <bits/stdc++.h>
using namespace std;
#define loop(n) for(int i=0;i<n;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define ll long long
#define s(x) scanf("%d", &x)
#define sd(x) scanf("%lf", &x)
#define sl(x) scanf("%lld", &x)
#define mod 1000000007
#define fi first
#define se second
#define p(x) printf("%d",x)
#define pl(x) printf("%lld", x)
#define pd(x) printf("%lf", x)
#define pn() printf("\n")
#define vi(v) vector<int>v
#define vl(v) vector<long long int>v
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define len(s) s.length()
void input(int n,int a[]){loop(n)cin>>a[i];}
ll bin_expo(ll A, ll B, ll M){ll res = 1LL;while (B > 0){if(B % 2 == 1){res = (res * A) % M;}A = (A * A) % M; B = B / 2;}return res;}

int main()
{
	ll fib[100005];
	fib[1]=2;
	fib[2]=4;
	ll n;
	cin>>n;
	ll m;
	cin>>m;
	for(int i=3;i<=n;i++)
	{
		fib[i]=(fib[i-1]+fib[i-2]+mod)%mod;
	}
	fib[1]=fib[n]%mod;
	fib[2]=(fib[1]+2)%mod;
	ll x=0,y=2;
	for(int i=3;i<=m;i++)
	{
		fib[i]=(fib[i-1]+x+y+mod)%mod;
		x=y;
		y=(fib[i]-fib[i-1]+mod)%mod;
	}
	cout<<fib[m]<<endl;
	return 0;
}
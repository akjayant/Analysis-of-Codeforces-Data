#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll __int64
#define mk(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pll pair<ll,ll>

#define eps 1e-5
const double pi=acos(-1);

#define ls (num<<1)
#define rs (num<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
#define MID int mid=(l+r)/2

const int maxn=300050;
const int maxm=500050;
const int inf=0x3f3f3f3f;
const int INF=0x7f7f7f7f;
#define mod 1000000007

using namespace std;

const string YES="YES";
const string NO="NO";
const string A="A";
const string B="B";

ll qpow(ll x,ll y)
{
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

ll inv(ll x,ll p)
{
	return qpow(x,p-(ll)2);
}

ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}

ll exgcd(ll a,ll b,ll &x,ll &y)
{
	ll d=a;
	if(b!=0){
		d=exgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	else{
		x=1;
		y=0;
	}
	return d;
}

int n;
int ans[500][500];

int main()
{
	cin>>n;
	int i,j;
	int cnt=0;
	for(j=1;j<=n;j++){
		if(j%2==1) for(i=1;i<=n;i++) ans[i][j]=++cnt;
		else for(i=n;i>=1;i--) ans[i][j]=++cnt;
	}
	for(i=1;i<=n;i++){
		printf("%d",ans[i][1]);
		for(j=2;j<=n;j++) printf(" %d",ans[i][j]);
		printf("\n");
	}
	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cctype>


#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ren(i,a,b) for(int i=a;i>=b;i--)
#define ff first
#define ss second
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<long long int>
#define vii vector<int>
#define gi(n) scanf("%d",&n)
#define gll(n) scanf("%lld",&n)
#define gstr(n) scanf("%s",n)
#define gl(n) cin >> n
#define oi(n) printf("%d",n)
#define oll(n) printf("%lld",n)
#define ostr(n) printf("%s",n)
#define ol(n) cout << n
#define os cout<<" "
#define on cout<<"\n"
#define o2(a,b) cout<<a<<" "<<b
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<vector<ll> > mat;

vll v1,v2;

ll dp[35][2][2];

ll f(int i,int on1,int on2)
{
	if(i>=35)
	{
		return 1;
	}
	if(dp[i][on1][on2]!=-1)return dp[i][on1][on2];
	ll &r=dp[i][on1][on2];
	r=0;
	ll hi1=v1[i],hi2=v2[i];

	int o1,o2;
	//0 0
	o1=on1,o2=on2;
	if(o1==1&&hi1==1)o1=0;
	if(o2==1&&hi2==1)o2=0;
	r+=f(i+1,o1,o2);

	//1 0
	o1=on1,o2=on2;
	if(o1==0||(o1==1&&hi1==1))
	{
		if(o2==1&&hi2==1)o2=0;
		r+=f(i+1,o1,o2);
	}

	//0 1
	o1=on1,o2=on2;
	if(o2==0||(o2==1&&hi2==1))
	{
		if(o1==1&&hi1==1)o1=0;
		r+=f(i+1,o1,o2);
	}
	return r;
}

ll go(ll n1,ll n2)
{
	if(n1<0||n2<0)return 0;
	v1.clear();
	v2.clear();
	rep(i,0,34)rep(j,0,1)rep(k,0,1)dp[i][j][k]=-1;
	while(1)
	{
		if(v1.size()==35)break;
		v1.pb(n1%2);
		n1/=2;
	}
	while(1)
	{
		if(v2.size()==35)break;
		v2.pb(n2%2);
		n2/=2;
	}
	reverse(all(v1));
	reverse(all(v2));
	return f(0,1,1);
}

int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
{
	ll l,r;
	cin>>l>>r;
	//o2(go(r,r),go(r,l-1));os;o2(go(l-1,r),go(l-1,l-1));on;
	ol(go(r,r)-go(r,l-1)-go(l-1,r)+go(l-1,l-1));on;
	ll ans=0;
//	rep(i,l,r)rep(j,l,r)
//	{
//		if(i+j==(i^j))
//		{
//			ans++;
//			o2(i,j);on;
//		}
//	}
//	ol(ans);on;
}

return 0;
}



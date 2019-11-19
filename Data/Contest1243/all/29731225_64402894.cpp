#include<bits/stdc++.h>
using namespace std;

#define IO ios::sync_with_stdio(false);cin.tie(0)
#define _rep(i,a,b) for(int i = (a);i<=(b);++i)
#define _for(i,a,b) for(int i = (a);i<(b);++i)
#define _dep(i,a,b) for(int i = (a);i>=(b);--i)
#define pb push_back
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()


typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
typedef vector<int> vi;

const int maxn = 300050;
const LL mod = 1e9+7;
		
int main(void)
{
	IO;
	LL n;
	cin>>n;
	vector<LL> g;
	for(LL i = 2;i*i<=n;i++)
	{
		if(n%i)continue;
		g.pb(i);
		g.pb(n/i);
	}
	if(g.empty())
	{
		return cout<<n<<endl,0;
	}
	LL ans = g[0];
	for(auto x:g)
		ans = __gcd(ans,x);
	cout<<ans<<endl;
	return 0;
}












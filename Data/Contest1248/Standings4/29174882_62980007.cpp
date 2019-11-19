#include <bits/stdc++.h>

using namespace std;
#define lowbit( x ) (x&(-x))
#define debug( x ) cout<<#x<<" is "<<x<<endl;
typedef long long ll;
const int N = 5e6 + 5;
#define pi acos(-1.0)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
typedef pair < int , int > P;
typedef pair < ll , int > PL;
int n , m;
bitset < 1005 > bs[10];
map<ll ,int > mp;

int main () {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int p;
		int c1= 0, c2=0;
		for(int i = 1;i<=n;i++){
			scanf("%d",&p);
			if(p&1) c1++;
			else c2++;
		}
		scanf("%d",&m);
		ll ans = 0;
		for(int i = 1;i<=m;i++){
			scanf("%d",&p);
			if(p&1) ans+=c1;
			else ans += c2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

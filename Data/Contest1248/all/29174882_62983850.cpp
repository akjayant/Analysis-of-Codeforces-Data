#include <bits/stdc++.h>

using namespace std;
#define lowbit( x ) (x&(-x))
#define debug( x ) cout<<#x<<" is "<<x<<endl;
typedef long long ll;
const int N = 1e5 + 5;
#define pi acos(-1.0)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
typedef pair < int , int > P;
typedef pair < ll , int > PL;
int n , m,a[N];
bitset < 1005 > bs[10];
map<ll ,int > mp;

int main () {
	scanf("%d",&n);
	int sum = 0;
	for(int i =1;i<=n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	sort(a+1,a+n+1,greater<int> () );
	int s = 0;
	for(int i =1;i<=(n+1)/2;++i) s+= a[i];
	ll ans = 1LL*s*s + 1LL*(sum-s)*(sum-s);
	printf("%lld\n",ans);

	return 0;
}

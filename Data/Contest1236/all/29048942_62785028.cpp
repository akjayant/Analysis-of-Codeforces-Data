#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef pair<int,int>   pii;
typedef vector< pii >  vii;
typedef long long int 	ll;

#define pb push_back
#define fe first
#define se second
#define all(a) (a).begin(),(a).end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define scn(n) scanf("%d",&n)
#define prn(n) printf("%d\n",n)
#define scnl(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mset(A, val) memset(A, val, sizeof(A))

const ll mod = 1e9 + 7ll;
const int N = (int)1e5 + 7;

int main(){
	
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int ans=0;
		int v1 = min(b,c/2);
		ans+=v1*3;
		b-=v1;
		c-=2*v1;
		int v2=min(a,b/2);
		ans+=v2*3;
		cout<<ans<<endl;
	}
	return 0;
}

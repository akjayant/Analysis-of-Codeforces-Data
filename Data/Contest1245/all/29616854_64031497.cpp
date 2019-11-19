#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define rep(i,n) for (int i=0;i<n;++i)
#define REP(i,n) for (int i=1;i<=n;++i)
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define read(x) scanf("%d",&x)
int t;
inline ll calc(int x,int y){
	int a[33],b[33],la=0,lb=0;
	ll dp[2][2][33];// 0:free 1:warn
	memset(dp,0,sizeof(dp));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	if (x<y) swap(x,y);// x>=y, la>=lb.
	if (x==0) return 1;
	while(x){
		a[++la]=x&1;x>>=1;
	}
	while(y){
		b[++lb]=y&1;y>>=1;
	}
	if (b[la]==1) dp[0][0][la]=1,dp[0][1][la]=1,dp[1][0][la]=1;
	else dp[0][1][la]=dp[1][1][la]=1;
	for (int i=la-1;i>=1;--i){
		if (a[i]==1&&b[i]==1){
			dp[0][0][i]=dp[0][0][i+1]*3+dp[0][1][i+1]*2+dp[1][0][i+1]*2+dp[1][1][i+1];
			dp[0][1][i]=dp[0][1][i+1]+dp[1][1][i+1];
			dp[1][0][i]=dp[1][0][i+1]+dp[1][1][i+1];
		}
		else if (a[i]==1&&b[i]==0){
			dp[0][0][i]=dp[0][0][i+1]*3+dp[1][0][i+1]*2;
			dp[0][1][i]=dp[0][1][i+1]*2+dp[1][1][i+1];
			dp[1][0][i]=dp[1][0][i+1];
			dp[1][1][i]=dp[1][1][i+1];
		}
		else if (a[i]==0&&b[i]==1){
			dp[0][0][i]=dp[0][0][i+1]*3+dp[0][1][i+1]*2;
			dp[1][0][i]=dp[1][0][i+1]*2+dp[1][1][i+1];
			dp[0][1][i]=dp[0][1][i+1];
			dp[1][1][i]=dp[1][1][i+1];
		}
		else{// 0,0
			dp[0][0][i]=dp[0][0][i+1]*3;
			dp[0][1][i]=dp[0][1][i+1]*2;
			dp[1][0][i]=dp[1][0][i+1]*2;
			dp[1][1][i]=dp[1][1][i+1];
		}
	}
	ll ret=dp[0][0][1]+dp[1][1][1]+dp[0][1][1]+dp[1][0][1];
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		int l,r;cin>>l>>r;
		if (l==0) cout<<calc(r,r)<<endl;
		else{
			ll ans=calc(r,r)-calc(l-1,r)*2+calc(l-1,l-1);
			cout<<ans<<endl;
		}
	}
	return 0;
}
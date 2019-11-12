#include <bits/stdc++.h>
#define int long long
#define MAXN 100005
#define INF 2000000000000000000
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
using namespace std;
typedef pair<int,int> pp;

int fastmul(int x,int so){
	int t; if (so==0) return 1;
	if (so==1) return x%MOD;
	t=fastmul(x,so/2); t=(t*t)%MOD; if (so%2==1) t=(t*x)%MOD;
	return t;
}
int m,n;
main(){
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("inp.txt","r",stdin);
	cin>>n>>m;
	int val=fastmul(2,m)-1; if (val<0) val+=MOD;
	//cout<<val<<'\n';
	int ans = fastmul(val,n);
	cout<<ans;
}
/* Beware of Constants and Constraints. Check again. 
If graph -> da do thi
If Multitest -> eye-check init() function
*/

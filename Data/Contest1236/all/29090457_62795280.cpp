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

int n; vector <int> ans[MAXN];
main(){
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("inp.txt","r",stdin);
	cin>>n;
	int i,j,k,cur=n,st;
	for(i=1;i<=n/2;i++){
		j=(i-1)*n+1; k=cur*n;
		for (st=1;st<=n;st++){
			ans[st].pb(j); ans[st].pb(k); j++; k--;
		}
		cur--;
	}
	if (n%2==1){
		j=n/2+1; k=(j-1)*n+1;
		for (st=1;st<=n;st++){
			ans[st].pb(k); k++;
		}
	}
	for (i=1;i<=n;i++){
		for (j=0;j<n;j++) cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
}
/* Beware of Constants and Constraints. Check again. 
If graph -> da do thi
If Multitest -> eye-check init() function
*/

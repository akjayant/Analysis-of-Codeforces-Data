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

int a,b,c;
main(){
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("inp.txt","r",stdin);
	int test; cin>>test;
	while (test--){
		cin>>a>>b>>c; int ans=0;
		while (c>=2&&b>=1){
			ans+=3; c-=2; b-=1;
		}
		while (a>=1&&b>=2){
			ans+=3; b-=2;  a-=1;
		}
		cout<<ans<<'\n';
	}
}
/* Beware of Constants and Constraints. Check again. 
If graph -> da do thi
If Multitest -> eye-check init() function
*/

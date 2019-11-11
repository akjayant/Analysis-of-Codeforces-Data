// dile a la jardinera que traigo flores
// corner cases // int vs ll // cin vs scanf // clear structures
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) int(x.size())
#define fill(x,v) memset(x,v,sizeof(x))
#define FER(i,a,b) for(int i = int(a); i < int(b); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define N 100050
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

ll dp[N];

int main(){

	fastio;
	string cad;
	cin >> cad;
	cad = "0" + cad;

	dp[0] = 1;
	for(int i = 1; i < sz(cad); ++i){
		char ch = cad[i], prev = cad[i-1];
		if(ch == 'm' or ch == 'w'){
			cout << 0 << endl;
			exit(0);
		}
		dp[i] = dp[i-1];
		if(ch == 'n' and prev == 'n') dp[i] = (dp[i]+dp[i-2])%MOD;
		if(ch == 'u' and prev == 'u') dp[i] = (dp[i]+dp[i-2])%MOD;
		
	}

	cout << dp[sz(cad)-1] << endl;

	return 0;
}

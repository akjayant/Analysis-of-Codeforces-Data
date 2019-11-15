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
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){

	fastio;
	int tc;
	cin >> tc;
	while(tc--){
		int n,a,b,c,r,s,p;
		string cad;
		cin >> n >> a >> b >> c;
		cin >> cad;
		string ans(n,'A');
		int wins = 0;
		for(int i = 0; i < n; ++i){
			if(cad[i] == 'R' and b){
				wins++;
				b--;
				ans[i] = 'P';
			}
		}
		for(int i = 0; i < n; ++i){
			if(cad[i] == 'S' and a){
				wins++;
				a--;
				ans[i] = 'R';
			}
		}
		for(int i = 0; i < n; ++i){
			if(cad[i] == 'P' and c){
				wins++;
				c--;
				ans[i] = 'S';
			}
		}
		for(int i = 0; i < n; ++i){
			if(ans[i] == 'A'){
				if(a) ans[i] = 'R', a--;
				else if(b) ans[i] = 'P', b--;
				else ans[i] = 'S', c--;
			}
		}
		if(wins >= (n+1)/2){
			cout << "YES" << endl;
			cout << ans << endl;
		}else cout << "NO" << endl;
	}

	return 0;
}

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

	int tc,a,b;
	cin >> tc;
	while(tc--){
		cin >> a >> b;
		if(__gcd(a,b) == 1) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}

	return 0;
}

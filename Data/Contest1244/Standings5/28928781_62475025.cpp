#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef std::vector<vector<int> > vvi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
#define debugone(x) cerr << #x << " " << x << "\n"; cerr.flush();
#define debugtwo(x) cerr << #x << "-------------" << "\n";for(auto &it: x) cerr << it << " ";cerr << "\n"; cerr.flush();
#define debugthree(x, i, j) cerr << #x << "------------" << "\n";cerr << "from " << i << " to " << j << "\n";for(ll k=i; k<=j; k++) cerr << x[k] << " ";cerr << "\n"; cerr.flush();
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
 
const ll MOD = 1e9 + 7;
const int INF = 2e9;
const int MAX_LOG = 21;
const int MAX_N = 750005;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int t;
	cin >> t;
	while(t--){	
		int n;
		cin >> n;
		string s;
		cin >> s;
		int first = -1, last = -1;
		for(int i = 0; i < n; i++){
			if(s[i] == '1'){
				first = i + 1;
				break;
			}
		}
		for(int i = n - 1; i >= 0; i--){
			if(s[i] == '1'){
				last = i + 1;
				break;
			}
		}
		int ans = n;
		if(first == -1){
			ans = n;
		}
		else{
			ans = max(ans, 2 * first);
			int y = n + 1 - first;
			ans = max(ans, 2 * y);
			ans = max(ans, 2 * last);
			int x = n + 1 - last;
			ans = max(ans, 2 * x);
		}	
		cout << ans << endl;
	}	
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define INF 1e9+7
#define pf2 pop_front
#define pb2 pop_back
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz size
#define eps 1e-7
#define fod find_by_order
#define fastio ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ofk order_of_key
#define val(x) cout << "Value dari "<< #x << " adalah " << x  << "\n"
#define tr tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;
using namespace __gnu_pbds;
using namespace std;

int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};

void readf(string x){
	freopen((x+".in").c_str(),"r",stdin);
	freopen((x+".out").c_str(),"w",stdout);
}

void pr(string x){
	freopen((x+".in").c_str(),"w",stdout);
}


int read()
{
	bool min = 0;
	int  result = 0;
	char ch;
	ch = getchar();
	while(1)
	{
		if(ch == '-') break;
		if(ch >='0' && ch <= '9') break;
		ch = getchar();
	}
	if(ch == '-') min = 1;else result = ch-'0';
	while(1)
	{
		ch =getchar();
		if(ch< '0' || ch>'9') break;
		result = result * 10 + (ch-'0');
	}
	if(min) return -result;
	return result;
}
//Reynaldo's Template

ll dp[32][2][2];
ll ans = 0;

vector<ll> ck1, ck2;
ll tmp1, tmp2;

vector<ll> konversi_digit(int a) {
	vector<ll> v; 
	while(a != 0){
		v.pb(a % 2);
		a /= 2;
	}
	
	for(int i = v.size(); i < 30; i++) {
		v.pb(0);
	}
	
	reverse(v.begin(), v.end());
	return v;
}

ll rec(ll pos, ll a, ll b) {
	//cout << pos << " " << a << " " << b << "sad\n";
	if (pos == ck1.size()) return 1;
	
	if (dp[pos][a][b] != -1 ) return dp[pos][a][b];
	ll ans = 0;
	
	if (a && b) {
		if (ck1[pos] && ck2[pos]) {
			ans = ans + rec(pos+1, 1, 0);
			ans = ans + rec(pos+1, 0, 0);
			ans = ans + rec(pos+1, 0, 1);
		}
		else if(ck1[pos]) {
			//ans = ans + rec(pos+1, 1, 0);
			ans = ans + rec(pos+1, 1, 1);
			ans = ans + rec(pos+1, 0, 1);
		}
		else if(ck2[pos]) {
			ans = ans + rec(pos+1, 1, 0);
			ans = ans + rec(pos+1, 1, 1);
		}
		else {
			ans = ans + rec(pos+1, 1, 1);
		}
	}
	else if(!a && !b) {
		ans += 3 * rec(pos+1, 0, 0);
	}
	else if(a) {
		if (ck1[pos]) {
			ans = ans + rec(pos+1, 1, 0);
			ans = ans + 2 * rec(pos+1, 0, 0); 
		}
		else {
			ans = ans + 2 * rec(pos+1, 1, 0);
		}
	}
	else if (b) {
		if (ck2[pos]) {
			ans = ans + rec(pos+1, 0, 1);
			ans = ans + 2 * rec(pos+1, 0, 0); 
		}
		else {
			ans = ans + 2 * rec(pos+1, 0, 1);
		}
		
	}
	//9cout <<pos << " " << a << " " << b << " "<<  ans << "sad\n";
	
	return dp[pos][a][b] = ans;
}

ll solve(ll a, ll b) {
	memset(dp, -1, sizeof dp);
	tmp1 = a;
	tmp2 = b;
	
	return rec(0, 1, 1);
}



int main() {
	int t;
	cin >> t;
	while(t--) {
		memset(dp, -1, sizeof dp);
		ll a, b;
		cin >> a >> b;
		ck1 = konversi_digit(b);
		ck2 = konversi_digit(b);
		ll ans = solve(b, b);	
		
		if (a != 0) {
			
			ck1 = konversi_digit(b);
			ck2 = konversi_digit(a - 1);
			
			ans = ans - 2 * solve(b, a-1);
		//	cout << ans << "sad\n";
			ck1 = konversi_digit(a-1);
			ck2 = konversi_digit(a-1);
			ans = ans + solve(a-1, a-1);
		}
		
		cout << ans << "\n";	
	}
}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define INF 1000000007
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

int main() {
	string s;
	cin >> s;
	int n = s.size();
	
	bool ga_valid = false;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'w' || s[i] == 'm') ga_valid = true;
	}
	
	if(ga_valid)  {
		cout << 0 << "\n";
		return 0;
	}
	
	ll dp[n+5];
	
	dp[n+1] = 1;
	for (int i = n; i >= 1; i--) {
		if (i == n) {
			dp[i] = 1;
		}
		else {
			dp[i] = dp[i+1];
			if ((s[i-1] == 'u' && s[i] == 'u') || (s[i-1] == 'n' && s[i] == 'n')) {
				dp[i] += dp[i+2];
			}	
			dp[i] %= INF;
		}
	}
	cout << dp[1] << "\n";
}

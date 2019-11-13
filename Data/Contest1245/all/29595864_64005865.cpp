#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using ull = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int,int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using Mii = map<int,int>;
using vMii = vector<Mii>;
using Si = set<int>;
using vSi = vector<Si>;
using vvSi = vector<vSi>;

#define fi first
#define se second
#define INF 1e9 + 5
#define mod(a,m) (a%m+m)%m
#define PB push_back
#define MP make_pair

const int MOD = 1e9 + 7;

int main(){
//	cout.setf(ios::fixed);
//	cout.precision(4);
	string s;
	while(cin >> s) {
		int n = s.size();
		vll dp(3, 0);
		dp[0] = 1;
		dp[2] = 1;
		if(s[0] == 'm' or s[0] == 'w') dp = vll(3, 0);
		for (int i = 1; i < n; ++i) {
			if(s[i] == 'm' or s[i] == 'w') dp = vll(3, 0);
			dp[i%3] = dp[(i+2)%3];
			if(s[i] == s[i-1] and (s[i] == 'u' or s[i] == 'n')) {
				dp[i%3] = (dp[i%3] + dp[(i+1)%3]) % MOD;
			}
		}
		cout << dp[(n+2)%3] << endl;
	}
}



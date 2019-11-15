#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
    in >> P.first >> P.second;
    return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
    out << "(" << P.first << ", " << P.second << ")";
    return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
    for(auto &x: arr) in >> x;
    return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
    for(auto &x: arr) out << x << ' '; cout << "\n";
    return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
    for(auto &x: arr) in >> x;
    return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
    for(auto &x: arr) out << x << ' '; cout << "\n";
    return out;
}
#define int long long

int mod = (int) 1e9 + 7;

const int N = 100005;

int dp[N];
int c[N];
string s;
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin>>s;
	bool tem = false;
	int n = s.size();	
	for(auto w : s){
		if(w == 'm' || w == 'w') tem = true;
	}
	if(tem){
		cout<<0<<endl;
		return 0;
	}
	c[0] = 1;
	dp[0] = 1;
	for(int i = 0 ; i < n; i ++){
		if(i){
			dp[i] = dp[i-1];
			c[i] = c[i-1];
		}
		if(i >=1){
			if(s[i] == 'u' && s[i-1] == 'u'){
				int cc = 1;
				if((i-2) >= 0) cc = dp[i-2];
				dp[i] = (dp[i] + cc)%mod;
				dp[i] %= mod;
			}
			if(s[i] == 'n' && s[i-1] == 'n'){
				int cc = 1;
				if((i-2) >= 0) cc = c[i-2];
				c[i] = (c[i] + cc)%mod;
				c[i] %= mod;
			}
		}
	}
	int u = (dp[n-1]*c[n-1])%mod;
	if(u == 0){
		u = 1;
	}
	cout << u << endl;
}
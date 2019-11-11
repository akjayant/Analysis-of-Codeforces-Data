// g++ -std=c++14
#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(c) c.begin(),c.end()
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

ll mod = 1e9 + 7;

int main(){
  _
  string s;
  cin >> s;
  int n = s.size();
  for(int i = 0; i < n; i++){
  	if(s[i] == 'w' or s[i] == 'm'){
  		cout << "0\n";
  		return 0;
  	}
  }
  vector<ll>cnt;
  int temp = 0;
  char prev = 'A';
  if(s[0] == 'u'){
  	temp = 1;
  	prev = 'u';
  }
  else if(s[0] == 'n'){
  	temp = 1;
  	prev = 'n';
  }
  for(int i = 1; i < n; i++){
  	if(s[i] != s[i - 1]){
  		if(temp > 1 and prev != 'A'){
  			cnt.pb(temp);
  		}
  		temp = 0, prev = 'A';
  		if(s[i] == 'u'){
  			temp = 1;
  			prev = 'u';
  		}
  		else if(s[i] == 'n'){
  			temp = 1;
  			prev = 'n';
  		}
  	}
  	else{
  		temp++;
  	}
  }
  	if(temp > 1 and prev != 'A'){
		cnt.pb(temp);
	}
	vector<ll>dp(1e5 + 10);
	dp[2] = 2;
	dp[3] = 3;
	for(int i = 4; i < 1e5 + 10; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= mod;
	}
	ll ans = 1;
	for(int i = 0; i < cnt.size(); i++){
		ans = (ans * dp[cnt[i]])%mod;
	}
	cout << ans << "\n";
  return 0;
}

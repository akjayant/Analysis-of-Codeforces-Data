#include <bits/stdc++.h>
using namespace std; 

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef long long ll; 
typedef long double ld; 
typedef vector<int> vi; 
typedef pair<int,int> pii; 
#define pb push_back
#define mp make_pair
#define prarr(a,n) cerr<<#a<<" : ";for(ll i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define prmat(mat,row,col) cerr<<#mat<<" :\n";for(ll i=0;i<row;i++) {for(ll j=0;j<col;j++) cerr<<mat[i][j]<<"\t";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
#define all(a) a.begin(),a.end()
#define sz(x) ((int)x.size())
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(NULL); cin.tie(NULL)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {ll idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
template <class T> void prall(T a) { prc(all(a)); }
const int inf=1000*1000*1000+9; 
const ll infl=1ll*inf*inf; 
const int mod=1000*1000*1000+7;  

// ----------------------------------------------------------------------------	-------------- 

void solve(){
	string s; cin>>s; 
	int n=s.size();
	vi dp(n); 
	dp[0]=1; 
	bool pos=1; 
	for(int i=0;i<n;i++){
		if(s[i]=='m' || s[i]=='w') pos=0; 
		if(i==0) continue; 
		if(s[i]=='n' && s[i-1]=='n'){
			dp[i]=dp[i-1]+(i>=2?dp[i-2]:1); 
		}
		else if(s[i]=='u' && s[i-1]=='u'){
			dp[i]=dp[i-1]+(i>=2?dp[i-2]:1); 
		}
		else {
			dp[i]=dp[i-1];
		}
		dp[i]%=mod; 
	}
	if(pos==0) cout<<0<<endl; 
	else 
		cout<<dp[n-1]<<endl; 
}




int main(){
	// clock_t beg=clock(); 
	fast_io; 
    cout << fixed << setprecision(13); 
	solve(); 	
	// clock_t end=clock(); 
	// fprintf(stderr, "%lf\n", (double)(end-beg)/(CLOCKS_PER_SEC));
}
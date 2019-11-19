#include <bits/stdc++.h>
using namespace std; 

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef long long ll; 
typedef long double ld; 
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

const int nax=1e5+5; 
ll dp[nax][2];
int exp(int a, int b, int M){
	ll ret=1; 
	while(b){
		if(b&1){
			ret*=a; 
			ret%=M;
		}
		b>>=1; 
		a=1ll*a*a%M; 
	}
	return ret; 
}
void solve(){
	int n,m; cin>>n>>m; 
	dp[0][1]=dp[0][0]=1; 
	if(n>m) swap(n,m); 
	for(int i=1;i<m;i++){
		dp[i][0]=(dp[i-1][1]+(i>=2? dp[i-2][1]:1))%mod; 
		dp[i][1]=(dp[i-1][0]+(i>=2? dp[i-2][0]:1))%mod; 
	}
	ll tot=(dp[m-1][0]+dp[m-1][1])%mod; 
	tot-=2; 
	tot+=(dp[n-1][0]+dp[n-1][0]); 
	tot%=mod; 
	cout<<tot<<endl; 
}


int main(){
	// clock_t beg=clock(); 
	fast_io; 
    cout << fixed << setprecision(13); 
	solve(); 	
	// clock_t end=clock(); 
	// fprintf(stderr, "%lf\n", (double)(end-beg)/(CLOCKS_PER_SEC));
}
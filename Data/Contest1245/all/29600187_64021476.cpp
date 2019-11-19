//By Tushar Gautam
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=1e5+5,MOD=1e9+7;
int t,n,m,k,x,y,w;
ll dp[35];
ll pw3[35];
void pre(){
	pw3[0]=1;
	forsn(i,1,35) pw3[i]=pw3[i-1]*3;
}
ll a,b;
ll dp2[35];
ll rec1(int i,int a){
	if(dp2[i]!=-1) return dp2[i];
	bool ba = (1ll<<i)&a;
	if(ba){
		if(i) dp2[i] = pw3[i]*2+rec1(i-1,a);
		else dp2[i] = pw3[i]*2+1;
		return dp2[i];
	}else{
		if(i==0) return dp2[i]=2;
		return dp2[i]=2*rec1(i-1,a);
	}
}
ll dp3[35];
ll rec2(int i,int a){
	if(dp3[i]!=-1) return dp3[i];
	bool ba = (1ll<<i)&a;
	if(ba){
		if(i) dp3[i] = pw3[i]*2+rec2(i-1,a);
		else dp3[i] = pw3[i]*2+1;
		return dp3[i];
	}else{
		if(i==0) return dp3[i]=2;
		return dp3[i]=2*rec2(i-1,a);
	}
}
ll rec(int i){
	if(i==-1) return 1;
	if(dp[i]!=-1) return dp[i];
	bool ba = (1ll<<i)&a;
	bool bb = (1ll<<i)&b;
	if(!ba && !bb){
		dp[i]=rec(i-1);
	}else if(ba && bb){
		dp[i] = pw3[i];
		if(i) dp[i] += dp2[i-1]+dp3[i-1];
		else dp[i] += 2;
	}else if(ba){
		dp[i]=rec(i-1);
		if(i) dp[i]+=dp3[i-1];
		else dp[i]++;
	}else{
		dp[i]=rec(i-1);
		if(i) dp[i]+=dp2[i-1];
		else dp[i]++;
	}
	// dbg(i,dp[i]);
	return dp[i];
}
ll solve(int r1,int r2){
	if(r1<0 or r2<0) return 0;
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	memset(dp3,-1,sizeof(dp3));
	a=r1,b=r2;
	rec1(31,a);
	rec2(31,b);
	return rec(31);
}
signed main(){
	fastio;
	pre();
	cin>>n;
	forn(i,n){
		cin>>x>>y;
		// dbg(solve(1,1));
		// dbg(solve(0,1));
		cout<< solve(y,y)+solve(x-1,x-1)-2*solve(x-1,y) <<ln;
	}
	return 0;
}
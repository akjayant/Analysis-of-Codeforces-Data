#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
#define MOD 1000000007
#define INF 1000000000
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
#define endl '\n'
#define pl cout<<endl;
void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL); }
const long long INFll=1ll*INF*INF;
const long double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define debug(x) cout << x << endl;
#define sz(a) int((a).size())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
long long genrand(long long L,long long R)
{
	return uniform_int_distribution<long long>(L, R)(rng);
}
//use brackets before operations if taking MOD
//use map only when necessary
//give long long to arrays and variables properly
int mul(int a, int b,int mod = MOD) {
	return int(a * 1ll * b % mod);
}
int norm(int a,int mod = MOD) {
	while(a >= mod) a -= mod;
	while(a < 0) a += mod;
	//a = (a%mod+mod)%mod;
	return a;
}
int powmod(int x,int y,int mod = MOD){
	int res = 1;
	while(y>0)
	{
		if(y&1)
			res = mul(res,x,mod);
		x = mul(x,x,mod);
		y=y>>1;
	}
	return res;
}
int inv(int a,int mod = MOD) {
	return powmod(a, mod - 2);
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("D:\\Codes\\in.txt", "r", stdin);
	freopen("D:\\Codes\\out.txt", "w", stdout);
	#endif	
	fast();
	int n,m; cin>>n>>m;

	vector<int> dp1(n+1),dp2(n+1),dp3(m+1),dp4(n+1);
	dp1[1] = 2; dp1[2] = 4;
	dp2[1] = 4;	dp2[2] = 6;
	dp4[1] = 0; dp4[2] = 2;
	for(int i = 3;i<=n;i++)
	{
		dp1[i] = (dp1[i-1]+dp1[i-2])%MOD;
		dp2[i] = (dp2[i-1]+dp2[i-2])%MOD; dp2[i] = (dp2[i]-2+MOD)%MOD;
		// cout<<dp1[i]<<' ';
		dp4[i] = (dp4[i-1]+dp4[i-2]+2)%MOD;
	}
	// pl;

	dp3[1] = dp1[n]; dp3[2] = dp2[n];
	for(int i = 3;i<=m;i++)
	{
		dp3[i] = (dp3[i-1]+dp3[i-2])%MOD;
		dp3[i] = (dp3[i] - dp4[n] + MOD)%MOD;
	}
	cout<<dp3[m];
	return 0;
}
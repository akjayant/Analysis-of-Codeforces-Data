#include <bits/stdc++.h>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
// #include <deque>
// #include <queue>
// #include <array>
// #include <ctime>
// #include <list>
#include <map>
#include <set>
// #include <complex>
// #include <cassert>
// #include <sstream>
// #include <forward_list>
// #include <unordered_set>
// #include <unordered_map> 
// #include <ctime>

using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> // Common file  
// #include <ext/pb_ds/tree_policy.hpp>  
// #include <functional> // for less  
// using namespace __gnu_pbds;  

// // Declaring ordered_set 
// typedef tree<int, 
//     null_type, 
//     less<int>, 
//     rb_tree_tag, 
//     tree_order_statistics_node_update>  
//     ordered_set;  

#define int long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define scani(n) scanf("%d",&n);
#define EPS 1e-9
#define arrinput for(int i=0; i<n; i++) cin>>arr[i];
#define sumarr for(int i=0; i<n; i++) sum+=arr[i];
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

typedef long long ll;  
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int MOD = 1e9+7;
const int n_ = 1e5+1000;
const long double PI = acos(-1.0);

ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vi dp(100005, 0);
	dp[1] = 2;
	dp[2] = 4;
	for(int i = 3; i < 100005; i++) dp[i] = (dp[i-1] + dp[i-2])%MOD;

	int n, m;
	cin>>n>>m;
	cout<<(dp[n] + dp[m] - 2 + MOD)%MOD;

	// int n;
	// cin>>n;
	// string s;
	// cin>>s;
	// int lo = -1, hi = n;
	// for0(i,n) {
	// 	if(s[i] == ')') {
	// 		lo = i;
	// 		break;
	// 	}
	// }
	// for0(i,n) {
	// 	if(s[i] == '(') {
	// 		hi = i;
	// 	}
	// }
	// int sum = 0;
	// for0(i,n) {
	// 	if(s[i] == '(') sum++;
	// 	else sum--;
	// }
	// if(lo == -1 || hi == n || sum != 0) {
	// 	cout<<0<<"\n";
	// 	cout<<1<<" "<<1;
	// 	return 0;
	// }
	// swap(s[lo], s[hi]);
	// string t = s + s;
	// int v[2*n];
	// for0(i,2*n) {
	// 	if(t[i] == ')') v[i] = -1;
	// 	else v[i] = 1;
	// }
	// int w[2*n+1];
	// for1(i,2*n-1) v[i] += v[i-1];
	// w[0] = 0;
	// for0(i,2*n) w[i+1] = v[i];
	// int ans = 0;
	// int *st = constructST(v, 2*n); 
	// cout<<s<<"\n";
	// for0(i,2*n) cout<<v[i]<<" "; cout<<"\n";
	// for0(i,2*n+1) cout<<w[i]<<" "; cout<<"\n";
	// for1(i,n) {
	// 	cout<<w[i]<<" "<<w[i+n]<<" "<<RMQ(st, 2*n, i-1, i+n-1)<<"\n";
	// 	if(w[i+n] - w[i] == 0 && RMQ(st, 2*n, i-1, i+n-1) >= w[i-1]) {
	// 		ans++;
	// 	}
	// }
	// cout<<ans<<"\n";
	// cout<<lo+1<<" "<<hi+1;

	return 0;
}
// #include <bits/stdc++.h>
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

	int t, n;
	string s;
	string r;;
	cin>>t;
	while(t--) {
		cin>>n;
		cin>>s>>r;
		vii ans;
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		for(char c: s) cnt[c - 'a']++;
		for(char c: r) cnt[c - 'a']++;
		// for0(i,26) cout<<cnt[i]<<" "; cout<<"\n";
		int f = 0;
		for0(i,26) if(cnt[i]%2) f = 1;
		if(f) {
			cout<<"No\n";
			continue;
		}
		// cout<<t<<endl;
		for0(i,n) {
			// cout<<"i "<<i<<endl;
			if(s[i] != r[i]) {
				int j = i + 1;
				while(j < n) {
					if(s[j] != r[i]) j++;
					else break;
				}
				// cout<<"j "<<j<<endl;
				if(j == n) {
					j = i + 1;
					// cout<<"j1 "<<j<<endl;
					while(j < n) {
						if(r[j] != r[i]) j++;
						else break;
					}
					// cout<<"j1 "<<j<<endl;
					if(j == n) {
						f = 1;
						break;
					}
					char a = s[i], b = r[j];
					s[i] = b; r[j] = a;
					ans.pb(mp(i+1, j+1));
				}
				else {
					char a = s[i], b = s[j], c = r[j];
					s[j] = c; r[j] = b;
					s[i] = b; r[j] = a;
					ans.pb(mp(j+1, j+1));
					ans.pb(mp(i+1, j+1));
				}	
			}
		}
		if(f) {
			cout<<"No\n";
			continue;
		}
		if(s == r) {
			cout<<"Yes\n";
			cout<<ans.size()<<"\n";
			for(pii a: ans) cout<<a.first<<" "<<a.second<<"\n";
		}
		else cout<<"No\n";
	}

	return 0;
}
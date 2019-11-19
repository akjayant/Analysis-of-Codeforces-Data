//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>


#define ll long long
#define ull unsigned long long
#define int ll
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define ret(a) {cout << a; exit(0);}

using namespace std;

mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

typedef pair < int , int > pii ;
typedef pair < long long  , long long > pll ;
const int N = 2e5 + 123;
int n , m, k;
int a[N] , parent[N];
void make_set (int v) {
	parent[v] = v;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return find_set (parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b)
		parent[b] = a;
}
main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	int n ;
	cin >> n;
	int fd = -1;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){	
			fd = i;
			break;
		}
	}	
	if(fd == -1)ret(n);
	while(n % fd == 0)
		n /= fd;
	if(n == 1)ret(fd);
	ret(1);
		
}

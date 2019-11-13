#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
using namespace __gnu_pbds;
using namespace std;
 
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define np(v) next_permutation(v.begin(), v.end())
#define pll pair < long long, long long>
#define all(a) a.begin(), a.end()
#define true false
#define false true
#define ull unsigned long long0
#define vll vector <long long>
#define pii pair < int, int >
#define sz(a) (int)(a.size())
#define sqr(x) ((x) * (x))
#define y1 stupid_cmath
#define vi vector <int>
#define pb push_back
#define mp make_pair
#define ll long long
#define lb lower_bound
#define f first
#define s second
#define endl "\n"
 
 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int inf = (int)1e9 + 100;
const ll INF = (ll)2e18;
const int mod = 998244353;
const double eps = 1e-9;
const int MaxN = 2e5 + 1;
const double pi = acos(-1.0);
ll bp (ll a, ll n) {
    ll res = 1;
    while (n) {
       if (n & 1)
           res *= a,res%=mod;
        a *= a,a%=mod;
        n >>= 1;
    }
    return res%mod;
}
 
 
 
ll gcd(ll a, ll b){
    while(b){
        a %= b;
        swap(a, b);
    }
   return a;
}
 
ll n,m,l,t,r,x1,y1,x2,y2,x3,y3,x4,y4,maxx=0,k,minn=inf,cnt,R,cnt2,cx,cy,pos,x,z,y;
ll a[1000100];

int main(){
	   cin>>t;
	   while(t--){
	   	cin>>n;
	   	for(ll i=0;i<n;i++)cin>>a[i];
	   	sort(a,a+n);
	   	maxx=1;
	   	for(ll i=0;i<n;i++)maxx=max(maxx,min(a[i],n-i));
	   	cout<<maxx<<endl;
	   }
 
}
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
using namespace __gnu_pbds; 
// GNU link : https://goo.gl/WVDL6g 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;
//insert(key) , *p.find_by_order(key), p.order_of_key(key),  
#define int long long
#define get1(x) int x; cin>>x
#define get2(x,y) int x,y; cin>>x>>y
#define get3(x,y,z) int x,y,z; cin>>x>>y>>z
#define min2(x,y) (x<y?x:y)
#define dbg(x) cout <<#x<<":"<<x<<endl;
#define dbg2(a,b) cout<<a<<" "<<b<<endl
#define dbg3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define dbg4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define max2(x,y) (x>y?x:y)
#define MOD 1000000007
#define set0(x) memset(x,0,sizeof(x))
#define rep(i,a,b) for(int i=a; i<b; i++)
#define repR(i,a,b) for(int i=b; i>=a; i--)
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define sz(v) v.size()
#define all(v)    v.begin(),v.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define printr(arr) {rep(i,0,sizeof(arr)/sizeof(arr[0])) cout<<arr[i]<<" "; cout<<endl;}
#define printv(arr) {rep(i,0,arr.size()) cout<<arr[i]<<" "; cout<<endl;}
#define PI 3.1415926535897932384626
#define f first
#define s second
#define vi vector<int>
#define vii vector<pii>
#define modInv(b,m) power(b,m-2,m)
#define modDiv(a,b,m) (power(b,m-2,m)*a)%m
int gcd(int a , int b){ if(b==0) return a;  a%=b; return gcd(b,a); } 
int power(int x,int y, int md=MOD){int res = 1;x%=md;while(y>0){if(y&1)res = (res*x)%md;x = (x*x)%md;y = y>>1;}return res%md;}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) { return (a.second < b.second);} 
#define inf 100000000000000000ll
int min1() {return inf;}
int max1() {return -inf;}
template<typename... Args>
int min1(int a, Args... args) {return min2(a,min1(args...));}
template<typename... Args>
int max1(int a, Args... args) {return max2(a,max1(args...));}
struct node {
	std::vector<int> v,w;
};
// Aditya/.config/sublime-text-3/Packages/User
//vector <pii> arr;



int32_t main(){
	boost;
//	#ifndef ONLINE_JUDGE
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
//	#endif // ONLINE_JUDGE

	get1(t);
	while(t--){
		get3(a,b,c);
		int sum = 0;
		if(b >= c/2) {
			sum += 3*(c/2);
			b -= c/2;

			if(a >= b/2) {
				sum += 3*(b/2);
				a -= b/2;
			}
			else{
				sum += 3*(a);
			}

		}
		else{
			sum += 3*b;
		}

		cout<<sum<<endl;

	}
	
	return 0;
}
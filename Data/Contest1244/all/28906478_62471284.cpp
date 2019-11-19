#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ll long long
#define ld long double

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define repA(i,A)   for(auto i:A)

#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl

#define mp make_pair
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)	A.rbegin(),A.rend()
#define ft first
#define sd second

#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V> 
#define Vpll vector<pll>

#define endl "\n"

const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

const ll N = 100005;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll no;
    cin>>no;
    while(no--){
    	ll n;
    	string s;
    	cin>>n>>s;
    	ll ans = n;
    	ll mi = -1, ma = n;
    	rep(i,0,n){
    		if(s[i]=='1'){
    			if(mi==-1)	mi = i+1;
    			ma = i+1;
    		}
    	}
    	if(mi == -1){
    		cout<<ans<<endl;
    	}
    	else{
    		ans = max(ans, max(mi-1, n-ma) + 2*(ma-mi+1));
    		ans = max(ans, 2*ma);
    		ans = max(ans, 2*(n-mi+1));
    		cout<<ans<<endl;
    	}
    }
    return 0;
}
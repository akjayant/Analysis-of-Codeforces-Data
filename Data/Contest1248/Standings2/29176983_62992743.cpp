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
    ll n,m;
    cin>>n>>m;
    ll a1=2,b1=4;
    rep(i,3,m+1){
    	ll t = (a1+b1)%M;
    	a1=b1;
    	b1=t;
    }
    ll a2=2,b2=4;
    rep(i,3,n+1){
    	ll t = (a2+b2)%M;
    	a2=b2;
    	b2=t;
    }
    if(n==1 and m==1){
    	cout<<2<<endl;
    }
    else if(n==1){
    	cout<<b1<<endl;
    }
    else if(m==1){
    	cout<<b2<<endl;
    }
    else{
    	cout<<((b1+b2-2)%M+M)%M<<endl;
    }
    return 0;
}
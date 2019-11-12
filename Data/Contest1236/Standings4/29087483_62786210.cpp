//This code is solely the property of StarnyC
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define int long long
#define hell 1000000007
#define hellx 998244353
#define pb push_back
#define mp make_pair
#define reset(a,b) memset(a,b,sizeof(a))
#define Go_Baby_Go  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0);
#define deb(x)     cout << (#x) << " is " << (x) << endl;
#define ff  first
#define ss  second
#define pii pair<ll,ll>
#define sz(a) (ll)((a).size())
#define all(c) (c).begin(),(c).end()
#define forn(i,n) for(int i=0;i<(int)n;i++)
 
 


ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);}
 
ll binexp(ll x,ll n,ll m){
   if(!n)return 1;
else if(n&1)return (x%m)*binexp((x%m)*(x%m),n/2,m)%m;
else if(!(n&1))return binexp((x%m)*(x%m),n/2,m)%m; 
return 0;}



int32_t solve(ll _,ll _t)
{   

	int a,b,c;

	cin>>a>>b>>c;

	int ans=0;

	while(c>=2 && b){
		c-=2;
		b--;
		ans++;

	}

	while(a && b>=2){
		b-=2;
		a--;
		ans++;
	}

cout<<3*ans<<endl;


}
 
int32_t main()
{
 Go_Baby_Go
//cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" ;
 
 
ll _=1;
cin>>_;
//cin.ignore();
ll _t=_;
while(_--)
solve(_,_t);
 
return 0;
 
}
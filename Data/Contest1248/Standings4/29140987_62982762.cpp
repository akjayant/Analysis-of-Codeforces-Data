//  A STUPID MONSTER :(
#include <bits/stdc++.h>
#define SPEED ios::sync_with_stdio(false); cin.tie(0)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define dbg(x) cout<<#x<<": "<<x<<endl
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mo 1000000007
#define inf 1e18
#define eps 0.0000000001
#define stp setprecision(20)
#define all(v) v.begin(),v.end()
#define endl '\n'
using namespace std;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

#define N  int(2e5)+10
int a[N];
int main()
{    SPEED;

       int n;cin>>n;ll x  = 0,y=0;
       loop(i,0,n){
       	  cin>>a[i];
	   }
	   sort(a,a+n,greater<int >());ll vll=0;
	   if(n&1)vll = n/2+1;else vll = n/2;
	   loop(i,0,n){
	   	if(i<vll) x+=a[i];else y+=a[i];
	   }
	   vll = x*x+y*y;cout<<vll;
	    
}



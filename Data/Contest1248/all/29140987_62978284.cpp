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

int main()
{    SPEED;

       int t;
	 cin>>t;
	   while(t--)
		  {
            ll n,m,o1=0,o2=0,e1=0,e2=0;cin>>n;int x;
			loop(i,0,n){cin>>x; 
            if(x&1)o1++;else e1++;
			}
			cin>>m;loop(i,0,m){cin>>x; 
            if(x&1)o2++;else e2++;
			}
			
			cout<<1LL*(o1*o2+e1*e2)<<endl;
	      }
}



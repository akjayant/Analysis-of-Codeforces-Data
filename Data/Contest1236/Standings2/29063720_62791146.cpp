// Brijesh Panara (201601074)
// DAIICT (India)
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FILL(a,b) memset((a),(b),sizeof((a)))
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<ll,vector<ll>,greater<ll> > 
#define maxQueue priority_queue<ll,vector<ll>,less<ll> > 

#define deb1(x) cout<<#x<<" : "<<x<<endl;
#define deb2(x,y) cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" : "<<x<<"   "<<#y<<" : "<<y<<"  "<<#z<<" : "<<z<<endl;

#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define READ freopen("input.txt","r",stdin);
#define WRITE freopen("output.txt","w",stdout);
#define RANDOM srand(time(NULL));

#define MOD 1000000007
#define NAX 1000005
#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN


ll solve()
{
    ll n;
    cin>>n;

    ll dp[n][n];
    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            dp[i][j]=j*n+i+1;
        }
    }

    ll temp = (n+1)/2;

    FOR(j,temp,n)
    {
        FOR(i,0,n)
        {
            ll t1 = i;
            ll t2 = n-i-1;
            if(t1<t2)
            swap(dp[t1][j],dp[t2][j]);
        }
    }
    
    FOR(i,0,n)
    {
        FOR(j,0,n)
        cout<<dp[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}


int main()
{
    FAST;
    
    ll t=1;
    // cin>>t;
    
    while(t--!=0)
    {
        ll stat = solve();
    }
    return 0;
}


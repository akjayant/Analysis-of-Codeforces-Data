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
    ll a,b,c;
    cin>>a>>b>>c;

    ll ans = 0;
    
    ll temp = min(b,c/2);
    ans += (temp+2*temp);

    b -= temp;
    c -= 2*temp;

    temp = min(a,b/2);
    ans += (temp+2*temp);

    a -= temp;
    b -= 2*temp;  
    
    cout<<ans<<"\n";
    return 0;
}


int main()
{
    FAST;
    
    ll t=1;
    cin>>t;
    
    while(t--!=0)
    {
        ll stat = solve();
    }
    return 0;
}

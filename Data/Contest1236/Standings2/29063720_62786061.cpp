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


//---------------------------------------------------------------------------//

//returns (x^(y))
ll pow(ll x, ll y)
{
    ll ans = 1;  
    while (y > 0)
    {
        if(y & 1)
        ans = (ans*x);
        y = y>>1;
        x = (x*x);  
    }
    return ans;
}

//returns (x^(y))%p
ll modpow(ll x, ll y, ll p=MOD)
{
    ll ans = 1;  
    x = x % p;  
    while (y > 0)
    {
        if(y & 1)
        ans = (ans*x) % p;
        y = y>>1;
        x = (x*x) % p;  
    }
    return ans;
}

//store gcd of a,b in ggg
//store solution of a*xxx + b*yyy = ggg in xxx,yyy
//if gcd(a,b)=1 then xxx = a^(-1)(mod b) and yyy = b^(-1)(mod a)
ll xxx,yyy,ggg;
void extendedEuclid(ll a, ll b)
{
    if(b==0)
    {
        ggg = a;xxx = 1;yyy = 0;
    }
    else
    {
        extendedEuclid(b,a%b);
        ll temp = xxx;
        xxx = yyy;
        yyy = temp-(a/b)*yyy;
    }
}

// return modulo inverse of a wrt modulo p
// retunt -1 if modulo inverse does not exist
ll modinverse(ll a, ll p=MOD)
{
    extendedEuclid(a,p);
    if(ggg==1 && p!=1)
        return (xxx+p)%p;
    else
        return -1;
}

ll madd(ll a,ll b,ll m=MOD) { return ((a%m)+(b%m))%m; }

ll msub(ll a,ll b,ll m=MOD) { return ((a%m)-(b%m)+m)%m; }

ll mmult(ll a,ll b,ll m=MOD) { return ((a%m)*(b%m))%m; }

ll mdiv(ll a,ll b,ll m=MOD) { return ((a%m)*modinverse((b%m),m))%m; }

//---------------------------------------------------------------------------//



ll solve()
{
    ll n,m;
    cin>>n>>m;

    ll ans = msub(modpow(2,m),1);
    ans = modpow(ans,n);
    
    cout<<ans<<"\n";
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

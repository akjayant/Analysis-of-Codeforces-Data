#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string>vst;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef map<int,int> dct;


#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
#define all(ct) ct.begin() , ct.end()
#define endl "\n"
#define fr(i,a) for(auto i:a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define in(d,v) d.find(v)!=d.end()
#define mp make_pair

bool compare(pll a, pll b)
{   return (a.first*b.second) < (a.second*b.first);
}

const int mod = 1e9 + 7;
const ll inf = ll(1e18);

ll modexp(ll x, ll n){
    if(n==0)return 1;
    if(n%2==0)return modexp((x*x)%mod,n/2);
    return (x*modexp((x*x)%mod,n/2))%mod;
}

int modinv(ll x){
    return modexp(x, mod-2ll);
}

int main() {
    //clock_t tm = clock();
    fastio;
    int t,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int ans=0;
        while(c>1 and b>0){
            ans+=3;c-=2;b--;
        }
        while(b>1 and a>0){
            ans+=3;b-=2;a--;
        }
        cout<<ans<<endl;
    }
    //cout<<((clock()-tm)*1.0)/CLOCKS_PER_SEC<<endl;
}
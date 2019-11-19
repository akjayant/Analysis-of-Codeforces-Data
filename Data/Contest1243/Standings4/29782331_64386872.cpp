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

bool compare(pair<int,pii> a, pair<int,pii> b){
    if(a.first!=b.first)return a.first>b.first;
    return a.second<b.second;
}

const int mod = 1e9 + 7;
const ll inf = ll(1e18);

ll modexp(ll x,ll n,ll k){
    if(n==0)return k;
    if(n%2==0)return modexp((x*x)%mod,n/2,k);
    return (x*modexp((x*x)%mod,n/2,k))%mod;
}


int main(){
    fastio;
    //clock_t tm = clock();
    ll n,k,t,x,y;string s1,s2;
//    cin>>t;
//    while(t--){
//        cin>>n;
//        cin>>s1;cin>>s2;
//
//    }
    cin>>n;ll cp=n;ll ans=0,ct=0;
    for(ll i=2;i<=sqrt(n);i++){
        if(cp%i==0) {
            ct++;
            while (cp % i == 0) {
                cp /= i;
                ans=i;
            }
        }
    }
    if(cp==n)cout<<n<<endl;
    else{
        if(ct>1 or (ct==1 and cp>1))cout<<1<<endl;
        else cout<<ans<<endl;
    }
    //cout<<((clock()-tm)*1.0)/CLOCKS_PER_SEC<<endl;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
#define FF first
#define SS second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define INF 1e18
#define MOD 1000000007
#define pi pair<ll,ll>
#define sc(x) scanf("%lld",&x)
#define pf(x) printf("%lld\n",x)
#define PI 3.14159265
typedef long long int lli;
typedef vector< lli > vlli;
typedef pair<lli,lli> plli;
typedef unordered_set<lli> slli;
typedef unordered_map<lli,lli> mlli;
 
ll pwr(ll base, ll p, ll mod){
    ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int t, n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        int st=-1, end=-1;
        int an;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                st=i+1;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(s[i]=='1'){
                end=i+1;
                break;
            }
        }
        if(st==-1 && end==-1){
            cout<<n<<endl;
            // cout<<"yes"<<endl;
        }
        else{
            an=(n-st+1)*2;
            an=max(an, n);

            an=max(an, end*2);
            cout<<an<<endl;
        }

    }

}
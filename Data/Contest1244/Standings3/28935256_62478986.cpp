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
    ll n, p, w, d;
    cin>>n>>p>>w>>d;
    ll tp, temp;
    bool ans=false;
    ll ind=-1;
    temp=p/w;
    ll cnt=0;
    if(p==0){
        cout<<"0 0 "<<n<<endl;

    }
    else{
        for(ll i=d+100; i>=0; i--){
            tp=p-temp*w;
            if(tp%d==0){
                ans=true;
                ind=temp;
                break;
            }
            temp--;
            if(temp<0){
                break;
            }
        }
        if(ans==true){
            tp=p-w*ind;
            tp=tp/d;
            cnt=ind+tp;
            if(cnt>n){
                cout<<"-1"<<endl;
            }
            else
                cout<<ind<<" "<<tp<<" "<<n-tp-ind<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
        
    

       

}
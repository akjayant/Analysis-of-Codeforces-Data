#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define repD(i, a, n) for(ll i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define init(n) int n;cin>>n;int a[n];rep(i,n)cin>>a[i];
const long double PI = 3.141592653589793238462643383;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;
long long int Ceil(int a, int b){
    if(a%b==0) return a/b;
    else return (a/b)+1;
}
ll p=1000000007;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n,m;cin>>n>>m;
    ll x=max(n,m);
    ll dp0[x+1];
    ll dp1[x+1];
    dp0[0]=0;
    dp1[0]=0;
    dp0[1]=1;
    dp1[1]=1;
    dp0[2]=2;
    dp1[2]=2;
    for(int i=3;i<=x;i++){
    	dp0[i]=dp1[i-2]+dp1[i-1];dp0[i]%=p;
    	dp1[i]=dp0[i-2]+dp0[i-1];dp1[i]%=p;
    }
    ll ans=0;
    ans=(dp0[m]+dp1[m]);ans%=p;
    ll cnt=dp0[n]+dp1[n];
    cnt=(cnt-2+p)%p;
    // cout<<dp1[3]<<endl;
    ans=ans+cnt;ans%=p;
    cout<<ans;
    return 0;
}
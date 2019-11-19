#include <bits/stdc++.h>
#define ll long long
using namespace std;
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define d(x) cout<<x<<endl;
#define fni(x,y,z) for(int i=(int)x;i>=(int)y;i-=(int)z)
#define fnj(x,y,z) for(int j=(int)x;j>=(int)y;j-=(int)z)
#define fpi(x,y,z) for(int i=(int)x;i<=(int)y;i+=(int)z)  
#define fpj(x,y,z) for(int j=(int)x;j<=(int)y;j+=(int)z)
#define fpk(x,y,z) for(int k=(int)x;k<=(int)y;k+=(int)z)  
#define fnk(x,y,z) for(int k=(int)x;k>=(int)y;k-=(int)z)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 1000000;
#define maxn 300005
#define mod (int)10e9+7
ll find(ll n)
{
    int dpb[n+1],dpw[n+1];
    dpb[0] = 1;
    dpw[0] = 1;
    dpb[1] = 1;
    dpw[1] = 1;
    fpi(2,n,1)
    {
        dpb[i] = dpw[i-1] + dpw[i-2];
        dpw[i] = dpb[i-1] + dpb[i-2];
        dpb[i]%=1000000007;
        dpw[i]%=1000000007;
    }
    dpb[n]+=dpw[n];
    dpb[n]%=1000000007;
    return dpb[n];
}
void solve()
{
    ll n,m,one=0,two=0;
    cin>>n>>m;
    ll ans = find(n) + find(m);
    ans%=1000000007;
    ans = (ans-2+1000000007)%1000000007;
    d(ans)
}
int main(){
    IOS;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    int t=1;
    //cin>>t;
    while(t--) solve();
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}

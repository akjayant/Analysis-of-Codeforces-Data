#pragma GCC optimize("O3")
#include <bits/stdc++.h>   
 
#define rep(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007
#define N 200005
#define se second
#define fi first
#define pie 3.14159265359
#define pll pair<ll,ll> 
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"
 
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
 
typedef long long ll;
using namespace std;

void solve(){
     ll n;
     cin >> n;
     if(n < 4){
        cout << n << "\n";
        return; 
     }
    ll i = 2;
    ll ans = n;
    while(i * i <= n){
        if(n % i == 0){
        ans = __gcd(ans,i);
        ans = __gcd(ans,n/i);
        }
        i++;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    //cin>>tc;
    while(tc--)solve();
    return 0;
}
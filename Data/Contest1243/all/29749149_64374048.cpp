#include<bits/stdc++.h>
using namespace std;
#define int long long int
// #define lli long long int
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define endl '\n'
#define all(x) x.begin(),x.end()
#define f(i,j,l) for(i=j;i<l;i++)
 
int const mod = 1e9+7;
int power(int a,int b){
    int res = 1;
    while(b){
        if(b&1){
            res = res*a;
            // res %= mod;
        }
        a=a*a;
        // a%=mod;
        b=b/2;
    }
    return res;
}
 
// int inverse_mod(int x){
//     return power(x,mod-2);
// }
 
int const N = 2e5+5;

void solve(){
    int n;
    cin>>n;
    int ans = 1;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        ans = max(ans , min(n-i , a[i]));
    }
    cout<<ans<<endl;
}


int32_t main(){
    IOS;
    int t;
    t = 1;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        solve();
    }
    return 0;
}
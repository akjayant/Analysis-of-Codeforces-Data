#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define pb       push_back
#define conv(a)  bitset<30>(a).to_string() ;
#define mxpq     priority_queue <int>
#define mnpq     priority_queue<int,vector<int>,greater<int>>
#define S(v)     sort(v.begin(),v.end())
#define RS(v)    sort(v.rbegin(),v.rend())
#define print    printf("%.16f\n", ans)
#define maxi     LLONG_MAX
#define mini     LLONG_MIN
#define T        int tc;cin>>tc;while(tc--)
#define int      long long 
#define MAXN     10000001
#define M        1000000007
#define fio      cin.sync_with_stdio(false) ; cin.tie(0);cout.tie(0) ;
#define endl     "\n"
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
int modpow(int n,int p){
    if(p==0) return 1 ;
    if(p%2==0){
        int x=modpow(n,p/2) ;
        return (x*x)%M ;
    }
    return (n*modpow(n,p-1))%M ;
}
int32_t main() {
    
     fio ;
     int n,m ; cin>>n>>m ;
     int x=modpow(2,m)-1 ;
     int ans=modpow(x,n) ;
     cout<<ans<<endl ;
}
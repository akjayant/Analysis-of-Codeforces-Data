#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policby.hpp>
 
#define ll long long int
#define mod 1000000007
using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int,null_tbpe,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    if(m>n){
        swap(n,m);
    }
    ll dp1[n][2];
    dp1[0][1]=1;dp1[0][0]=1;
    dp1[1][1]=2;dp1[1][0]=2;
    for(ll i=2;i<n;i++){
        dp1[i][0] = (dp1[i-1][1]+dp1[i-2][1])%mod;
        dp1[i][1] = (dp1[i-1][0]+dp1[i-2][0])%mod;
    }
    
    cout<<(2*dp1[n-1][0]+2*dp1[m-1][0]-2)%mod;

    return 0;
}
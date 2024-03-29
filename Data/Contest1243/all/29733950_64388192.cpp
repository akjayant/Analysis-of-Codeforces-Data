#include<bits/stdc++.h>
#include<ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
#define ld long double
#define pb push_back
#define pa pair<int,int>
#define v1d vector<int>
#define v2d vector<vector<int>>
#define v1p vector<pa>
#define INF 1000000007
#define M 998244353
#define mp make_pair
#define RS(v)    sort(v.rbegin(),v.rend())
#define PI 3.14159265
#define ff first
#define ss second
#define endl "\n"
#define v1s vector<string>
#define S(v) sort(v.begin(),v.end())
#define mxpq priority_queue <int>
#define mnpq priority_queue<int,vector<int>,greater<int>>

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
pbds;



void solve(){



    int n;
    cin>>n;

    vector<int> v;
    for(int i = 2 ; i*i <= n ; i++){

        if(n % i == 0){
            v.pb(i);
            v.pb(n/i);
        }
    }

    if(v.size() == 0){
        cout<<n<<endl;
    }else{

        int ans = v[0];

        for(auto i : v){
            ans = __gcd(i , ans);
        }

        cout<<ans<<endl;
    }


}
 
 
int32_t main(){
    
    
    cout<<fixed<<setprecision(16);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
    // #ifndef ONLINE_JUDGE
    //  freopen("input.txt",  "r",  stdin);
    //  freopen("output.txt", "w", stdout);
    // #endif
    
    int tc = 1;
    // cin>>tc;

    while(tc--){
        solve();
    }

}
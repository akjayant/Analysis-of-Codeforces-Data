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

    
    string s1 , s2;

    cin>>s1>>s2;

    std::vector<char> d2;
    std::vector<char> d1;
    for(int i = 0 ; i  < n ; i++){

        if(s1[i] == s2[i]){
            continue;
        }else{
            d1.pb(s1[i]);
            d2.pb(s2[i]);
        }
    }

    if(d1.size() == 0 || d1.size() == 2){

        if(d1.size() == 0){
            cout<<"YES"<<endl;
            return;
        }

        if(d1[0] == d1[1] && d2[0] == d2[1]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
            return ;
        }
    }else{
        cout<<"NO"<<endl;
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
    cin>>tc;

    while(tc--){
        solve();
    }

}
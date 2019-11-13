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

bool issame(string &s1 , string &s2){

    map<char , int> mp;

    for(auto i : s1){
        mp[i]++;
    }
    for(auto i : s2){
        mp[i]++;
    }

    for(auto i : mp){
        if(i.ss % 2){
            return 0;
        }
    }

    return 1;
}

void solve(){



    int n;
    cin>>n;

    string s1,s2;
    cin>>s1>>s2;

    vector<set<int>> v1(26);
    vector<set<int>> v2(26);

    if(!issame(s1,s2)){
        cout<<"NO"<<endl;
        return;
    }

    int idx = 0;
    for(auto i : s1){
        v1[i-'a'].insert(idx);
        idx++;
    }


    idx = 0;
    for(auto i : s2){
        v2[i-'a'].insert(idx);
        idx++;
    }

    v1p ans;

    for(int i = 0 ; i < n ; i++){

        char c1 = s1[i];
        char c2 = s2[i];

        if(c1 == c2){
            v1[c1-'a'].erase(i);
            v2[c1-'a'].erase(i);
            continue;
        }

        // cout<<v2[c1].size()<<" ";
        if(v2[c1 - 'a'].size() != 0){
                int temp = *(v2[c1 - 'a'].begin());

                ans.pb({temp,temp});
                ans.pb({temp , i});

                // cout<<temp<<" "<<i<<endl;
                v1[s1[temp] -'a'].erase(temp);
                v2[s2[temp]-'a'].erase(temp);

                swap(s1[temp] , s2[temp]);
                // v2[c1].erase(temp);

                v1[s1[temp]-'a'].insert(temp);
                v2[s2[temp]-'a'].insert(temp);


                v1[s1[temp]-'a'].erase(temp);
                v2[s2[i]-'a'].erase(i);


                swap(s1[temp] , s2[i]);

                v1[s1[temp]-'a'].insert(temp);
                v2[s2[i]-'a'].insert(i);


                v1[c1-'a'].erase(i);
                v2[c1-'a'].erase(i);
        }else{

                v1[c1-'a'].erase(i);

                int temp = *(v1[c1-'a'].begin());

                ans.pb({temp , i});
                v1[s1[temp]-'a'].erase(temp);
                v2[s2[i]-'a'].erase(i);


                swap(s1[temp] , s2[i]);

                v1[s1[temp]-'a'].insert(temp);
                v2[s2[i]-'a'].insert(i);


                v2[c1-'a'].erase(i);


        }
        





    }

    cout<<"YES"<<endl<<ans.size()<<endl;
    for(auto i : ans){
        cout<<i.ff+1<<" "<<i.ss+1<<endl;
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
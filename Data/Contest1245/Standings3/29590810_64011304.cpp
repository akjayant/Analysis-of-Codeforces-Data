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
// #define mp make_pair
#define RS(v)    sort(v.rbegin(),v.rend())
#define print(a) printf("%.16f\n", a);
#define PI 3.14159265
#define ff first
#define ss second
#define ump map<int,int>
#define endl "\n"
#define v1s vector<string>
#define S(v) sort(v.begin(),v.end())
#define mxpq priority_queue <int>
#define mnpq priority_queue<int,vector<int>,greater<int>>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fff cout.flush();


 
int32_t main(){
    
    fio

    int tc = 1;
    // cin>>>tc;

    while(tc--){

        vector<int> v(1000000);

        v[2] = 2;
        v[3] = 3;
        v[1] = 1;
        for(int i = 4 ; i < v.size() ; i++){

            v[i] = (v[i-1] + v[i-2])%INF;
        }
        
        // for(auto i : v){
        //     cout<<i<<" ";
        // }

        string str;

        cin>>str;
        
        // cout<<str<<" ";

        char last = '$';

        int cnt = 0;
        int ans = 1;
        int n = str.size();
        for(int i = 0 ; i < n ; i++){
            
            char ch = str[i];
            // cout<<ch<<" ";
            if(str[i] == 'm' || str[i] == 'w' ){
                cout<<0;
                return 0;
            }
            
            if(last == 'n'){

                if(str[i] == 'n'){
                    cnt++;
                }else{
                    ans *= v[cnt];
                    last = ch;
                    cnt = 1;
                    // ans *= v[cnt];
                    ans %= INF;
                }
                

            // cout<<ans<<" "<<last<<endl;;
                continue;
            }

            if(last == 'u'){

                if(str[i] == 'u'){
                    cnt++;
                }else{
                    ans *= v[cnt];
                    last = ch;
                    cnt = 1;
                    ans%=INF;
                }
                
            // cout<<ans<<" "<<last<<endl;;
                continue;
            }
            
            
            last = ch;
            cnt = 1;
            // cout<<ans<<" "<<last<<endl;;

        }  
    
        ans *= v[cnt];
        ans%=INF;

        cout<<ans;
        

}

}
 

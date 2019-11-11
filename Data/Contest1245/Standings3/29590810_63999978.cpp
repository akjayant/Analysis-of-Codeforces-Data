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

    int tc;
    cin>>tc;

    while(tc--){

        
        int n;
        cin>>n;
        int r,p,s;
        cin>>r>>p>>s;

        string str;
        cin>>str;

        int cnt = 0;
        string ans;

        for(int i = 0 ; i < n ; i++){

            if(str[i] == 'R'){
                if(p > 0){
                    ans.pb('P');
                    cnt++;
                    p--;
                }else{
                    ans.pb('#');
                }
            }else if(str[i] == 'P'){

                if(s > 0){
                    ans.pb('S');
                    cnt++;
                    s--;
                }else{
                    ans.pb('#');
                }
            }else{

                if(r > 0){
                    ans.pb('R');
                    cnt++;
                    r--;
                }else{
                    ans.pb('#');
                }
            }
        }


        int req = n/2;
        req += n%2;

        if(cnt >= req){
            cout<<"YES"<<endl;

            for(auto &i : ans){
                if(i == '#'){

                    if(r > 0){
                        i = 'R';r--;
                    }else if(s > 0){
                        i = 'S';s--;
                    }else{
                        i = 'P' ; p--;
                    }
                }

                cout<<i;
            }cout<<endl;
        }else{
            cout<<"NO"<<endl;;
        }
    }



}
 

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

        int a ,b;
        cin>>a>>b;


        if(__gcd(a,b) == 1){
            cout<<"Finite"<<endl;
        }else{
            cout<<"Infinite"<<endl;
        }
    }



}
 

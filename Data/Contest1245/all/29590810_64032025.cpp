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
#define pa pair<int,pair<int,int>>
#define v1d vector<int>
#define v2d vector<vector<int>>
#define v1p vector<pair<int,int>>
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

int parr(int i , v1d &v){

    while(v[i] != i){
        i = v[i];
    }

    return i;
}

void unionn(int a , int b , v1d &sze , v1d &p){

    sze[b] += sze[a];

    p[a] = b;
}
int32_t main(){
    
    fio


    int n;
    cin>>n;

    v1p v(n);

    for(int i = 0 ; i  < n ; i++){
        cin>>v[i].ff>>v[i].ss;
    }

    v1d cost(n);

    for(auto &i : cost){
        cin>>i;
    }

    v1d k(n);

    for(auto &i : k){
        cin>>i;
    }

    priority_queue<pa,vector<pa>,greater<pa>> q;


    for(int i= 0 ; i  < n ; i++){
        for(int j  = i+1 ; j < n ; j++){


            int c  = (abs(v[i].ff - v[j].ff) + abs(v[i].ss - v[j].ss)) * (k[i] + k[j]);
            // cout<<c<<" ";
            q.push({c , {i , j }});


        }
    }
    
    // cout<<endl;

    for(int i = 0 ; i < n ; i++){
        q.push({cost[i] , {-1 , i}});
    }

    v1d isit(n+1 , 0);

    v1d par(n);

    for(int i = 0 ; i  <n  ;i++){
        par[i] = i;
    }

    v1d sze(n+1 , 1);

    int ans = 0;

    v1d lans;
    v1p bijli;
    while(q.size()){

        pa p = q.top();
        q.pop();


        int a = p.ss.ff;
        int b = p.ss.ss;
        int c = p.ff;
        
        // cout<<c<<" "<<a<<endl;
        if(a == -1){
            int temp = b;
            b = parr(b , par);

            if(isit[b]){
                continue;
            }else{
                isit[b]++;
                ans += c;
                lans.pb(temp);
            }
        }else{

            int tempa = a;
            int tempb = b;

            a = parr(a , par);
            b = parr(b , par);

            int k = 0 ;
            int temp = 0;

            if(isit[a] == 1 || isit[b] == 1){
                temp =1;
            }
            
            if(isit[a] && isit[b]){
                continue;
            }

            if(a == b){
                continue;
            }else{

                ans += c;
                bijli.pb({tempa , tempb});
                if( sze[a] < sze[b]){
                    unionn(a , b , sze , par);
                }else{
                    unionn(b , a , sze , par);
                }

                if(temp){
                    a = parr(a,par);
                    isit[a] = 1;
                }

            }
        }

    }


    cout<<ans<<endl;
    cout<<lans.size()<<endl;

    for(auto i : lans){
        cout<<i+1<<" ";
    }cout<<endl;

    cout<<bijli.size()<<endl;

    for(auto i : bijli){
        cout<<i.ff+1<<" "<<i.ss+1<<endl;
    }



        



}
 

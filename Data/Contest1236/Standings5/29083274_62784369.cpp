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
#define M1       10000000007
#define fio      cin.sync_with_stdio(false) ; cin.tie(0);cout.tie(0) ;
#define endl     "\n"
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
int32_t main() {
    
     fio ;
     T{
         int a,b,c ;
         cin>>a>>b>>c ;
         int ans1=0 ;
         int ans2=0 ;
         {
           while(true){
               if(b<1 || c<2) break ;
                b=b-1 ;
                c=c-2 ;
                ans1=ans1+3 ;
           }
           while(true){
               if(a<1 || b<2) break ;
                a=a-1 ;
                b=b-2 ;
                ans1=ans1+3 ;
           }
         }
         {
            while(true){
               if(a<1 || b<2) break ;
                a=a-1 ;
                b=b-2 ;
                ans2=ans2+3 ;
           }
           while(true){
               if(b<1 || c<2) break ;
                b=b-1 ;
                c=c-2 ;
                ans2=ans2+3 ;
           }
           
         }
         cout<<max(ans1,ans2)<<endl ;
     }
}
/**                                                     **\
 *    created by:   Divianshu Bansal                     *
 *    e-mail id:    god_coder@icloud.com                 *
*                                                        */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>


using namespace std;
using namespace __gnu_pbds;


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>new_data_set;
#define MOD 1000000007
#define int long long
#define BIG 998244353
#define pf push_front
#define print(x) for(auto el: x) cout<<el<<" ";cout<<endl
#define bits(x) __builtin_popcount(x)
#define ff first
#define se second
#define pb push_back
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define PSET(x,y) fixed<<setprecision(y)<<x
#define mp make_pair
#define pi 3.141592653589


int power(int x,int y){
    int r=1,z=x;
    while(y){
        if(y & 1)r*=z;
        z*=z;y=y>>1;}
    return r;}
int powerm(int x,int y,int p){
    int r=1;
    while(y){
        if(y & 1)r=(r*x)%p;
        y=y>>1;
        x=(x*x)%p;}
    return r%p;}
int modinv(int x,int m){
    return powerm(x,m-2,m);}
int logarithm(int a,int b){
    int x=0;
    while(a>1){
        x++;
        a/=b;}
    return x;}
int max3(int a,int b,int c){
    return max(a,max(b,c));
}
int min3(int a,int b,int c){
    return min(a,min(b,c));
}
void under_rated(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
}


int32_t main(){
    under_rated();
    fast;
    int t;cin>>t;while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;++i){
            cin>>v[i];
        }
        sort(v.rbegin(),v.rend());
        int ans = 0;
        for(int i=0;i<n;++i){
            if(v[i]>ans){
                ++ans;
            }
            else{
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
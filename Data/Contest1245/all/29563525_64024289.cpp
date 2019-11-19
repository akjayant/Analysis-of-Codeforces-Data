//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 1000000007
#define fi first
#define se second
#define pii pair<int,int>
#define int long long
#define endl '\n'
#define pll pair<long long,long long>
//#define LONGLONG_MAX 10000000000000000
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
long long power(long long a,long long b){
    long long ans=1;
    while(b>0){
        if(b&1){ans=(ans*a)%mod;}
                a=(a*a)%mod;
                b>>=1;
        }
    return ans;
        
}
const double eps=1e-15,x=double(1)/double(6);
int a[10][10];
double dp[10][10][2][100];
double fun(int i,int j,int k,int l){
    //cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
    //cout<<l<<endl;
    //cout<<dp[i][j][k][l]<<" ";
    //if(i>9)return INT_MAX;
    
    if(i==9&&j==0){
        return 0;
    }
    if(l==100)return 0;
    if(dp[i][j][k][l]!=0)return dp[i][j][k][l];
    if(k==1)return dp[i][j][k][l]=min(fun(i+a[i][j],j,0,0),fun(i,j,0,0));
    double ans=1;
    if(i==9){
        for(int u=1;u<7;u++){
            if(j-u<0){
                ///cout<<l<<endl;
                ans+=((x*fun(i,j,0,l+1)));
            }
            else ans+=((x*fun(i,j-u,0,0)));
        }
    }
    else if(i&1){
        for(int u=1;u<7;u++){
            if(j-u<0){
                ans+=(x*fun(i+1,u-j-1,1,0));
            }
            else ans+=(x*fun(i,j-u,1,0));
        }
    }
    else{
        for(int u=1;u<7;u++){
            if(j+u>9){
                ans+=(x*fun(i+1,19-(j+u),1,0));
            }
            else ans+=(x*fun(i,j+u,1,0));
        }
    }
    return dp[i][j][k][l]=ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=9;i>=0;i--){
        for(int j=0;j<10;j++){
            cin>>a[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
    //fun(9,1,1,0);
    cout<<fixed<<setprecision(10)<<fun(0,0,1,0);
    return 0;
}
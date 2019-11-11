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
int dp[100005];
int fun(int i,int n,string &s){
    if(i==n-1||i==n){
        return 1;
    }
    if(dp[i]!=-1)return dp[i];
    int ans=fun(i+1,n,s);
    if(s[i]=='u'&&s[i+1]=='u'){
        ans+=fun(i+2,n,s);
        ans%=mod;
    }
    if(s[i]=='n'&&s[i+1]=='n'){
        ans+=fun(i+2,n,s);
        ans%=mod;
    }
    return dp[i]=ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    int n=s.size();
    for(auto i:s){
        if(i=='w'||i=='m'){
            cout<<0;
            return 0;
        }
    }
    cout<<fun(0,n,s);
    return 0;
}
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    if((n&(n-1))==0){
        cout<<2;
        return 0;
    }
    bool b=true;
    vector<int>v;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)v.push_back(i);
        if(i*i!=n&&n%(n/i)==0)v.push_back(n/i);
    }
    if(v.size()==0){
        cout<<n;
        return 0;
    }
    if(n%2==0&&v.size()>1){
        cout<<1;
        return 0;
    }
    int x=v[0];
    for(auto i:v){
        x=__gcd(x,i);
    }
    cout<<x;
    return 0;
}


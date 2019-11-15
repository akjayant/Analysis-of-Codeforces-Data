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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i])v.push_back(i);
        }
        bool b=false;
        if(v.size()==0){
            b=true;
        }
        if(v.size()==2){
            if(t[v[0]]==t[v[1]]&&s[v[1]]==s[v[0]])b=true;
        }
        if(b)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
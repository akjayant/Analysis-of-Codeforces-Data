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
    int t1;
    cin>>t1;
    while(t1--){
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int a[26]={0};
        for(auto i:s)a[i-'a']++;
        for(auto i:t)a[i-'a']++;
        bool b=true;    
        for(int i=0;i<26;i++){
            if(a[i]&1){
                cout<<"NO"<<endl;
                b=false;
                break;
            }
        }
        if(!b)continue;
        cout<<"YES"<<endl;
        vector<pii>v;
        for(int i=0;i<n;i++){
            if(s[i]==t[i])continue;
            bool k=true;
            for(int j=i+1;j<n;j++){
                if(s[j]==t[i]){
                    v.push_back({j+1,n});
                    swap(s[j],t[n-1]);
                    v.push_back({i+1,n});
                    swap(s[i],t[n-1]);
                    k=false;
                    break;
                }
                if(s[i]==t[j]){
                    v.push_back({n,j+1});
                    swap(s[n-1],t[j]);
                    v.push_back({n,i+1});
                    swap(s[n-1],t[i]);
                    k=false;
                    break;
                }
            }
            if(!k)continue;
            for(int j=i+1;j<n;j++){
                if(s[j]==s[i]){
                    v.push_back({j+1,i+1});
                    swap(t[i],s[j]);
                    break;
                }
                if(t[j]==t[i]){
                    v.push_back({i+1,j+1});
                    swap(s[i],t[j]);
                    break;
                }
            }
        }
        cout<<v.size()<<endl;
        for(auto i:v){
            cout<<i.fi<<" "<<i.se<<endl;
        }    
    }
    return 0;
}
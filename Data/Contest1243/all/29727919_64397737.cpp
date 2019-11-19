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
vector<vector<int>>v;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        sort(v[i].begin(),v[i].end());
    }
    vector<bool>b(n,true);
    int ans=0;
    for(int i=0;i<n;i++){
        if(b[i]){
            ans++;
            set<int>s(v[i].begin(),v[i].end());
            queue<int>q;
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(s.find(j)==s.end())q.push(j);
            }
            while(!q.empty()){
                int x=q.front();
                q.pop();
                b[x]=false;
                set<int>s1;
                for(auto i:s){
                    if(binary_search(v[x].begin(),v[x].end(),i))s1.insert(i);
                    else q.push(i);
                }
                s=s1;
            }
        }
    }
    cout<<ans-1;
    return 0;
}
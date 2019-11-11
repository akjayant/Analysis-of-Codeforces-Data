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
        int a,b,c;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        int ans=0;
        char s1[n];
        for(int i=0;i<n;i++){
            s1[i]='a';
        }
        for(int i=0;i<n;i++){
            if(s[i]=='S'){
                if(a!=0){
                    ans++;
                    a--;
                    s1[i]='R';
                }
            }
            else if(s[i]=='P'){
                if(c!=0){
                    c--;
                    ans++;
                    s1[i]='S';
                }
            }
            else{
                if(b!=0){
                    b--;
                    ans++;
                    s1[i]='P';
                }
            }
        }
        for(int i=0;i<n;i++){
            if(s1[i]=='a'){
                if(a!=0){
                    s1[i]='R';
                    a--;
                }
                else if(b!=0){
                    s1[i]='P';
                    b--;
                }
                else s1[i]='S';
            }
        }
        if(ans>=(n+1)/2){cout<<"YES"<<endl;for(int i=0;i<n;i++)cout<<s1[i];cout<<endl;}
        else cout<<"NO"<<endl;
    }
    return 0;
}
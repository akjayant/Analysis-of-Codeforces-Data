#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(i,A,B) for(int i=A;i<=B;i++)
#define mod 998244353
#define v1d vector<int>
#define v1c vector<char>
#define v2d vector<vector<int>>
#define v1s vector<string>
#define vip vector<pair<int,int> >
#define v2p vector<vector<pair<int,int> > >
#define v2s vector<vector<string> >
#define vsp vector<pair<string,string> >
#define pa pair<int,int>
 
int32_t main(){
    IOS;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int e1=0,o1=0,e2=0,o2=0;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(a&1)o1++;
            else e1++;
        }
        int m;cin>>m;
        for(int i=0;i<m;i++){
            int a;cin>>a;
            if(a&1)o2++;
            else e2++;
        }
        int p= o1*o2+ e2*e1;
        cout<<p<<endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
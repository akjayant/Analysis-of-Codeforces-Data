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
    int n;cin>>n;
    v1d a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int i=0,j=n-1;
    int x=0,y=0;
    while(i<=j){
        if(i==j){
            y+= a[j];break;
        }
        x+= a[i];
        y+= a[j];
        i++;j--;
    }
    //cout<<x<<" "<<y<<endl;
    int p= x*x+ y*y;
    cout<<p;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
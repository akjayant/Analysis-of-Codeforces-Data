#include <bits/stdc++.h>

#define int         long long
#define ld          long double
#define pb          push_back
#define pii         pair<int,int> 
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define mem(x)      memset(x,0,sizeof(x));
#define what_is(x)  cerr << #x << " is " << x << endl;
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define hash1       105727LL
#define M           hell
#define eps         1e-10
#define pi          3.141592653589793238462643383279502884197

 
using namespace std;



void solve(){
    int n;
    cin>> n;
    vector<int> a[n];

    int l=1,r=n*n;

    while(l<=r){
        rep(i,0,n){
            if(a[i].size()!=n){
                a[i].push_back(l);
                l++;
            }
            if(a[i].size()!=n){
                a[i].push_back(r);
                r--;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(auto x: a[i])cout<<x<<" ";
        cout<<endl;
    }
    


}
 
 
 
signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
   
 
    int t=1;
    //cin>>t;
    
 
    while(t--){
       
        solve();
    
    }
 
    return 0;
}

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
    int a,b,c;
    cin>> a >> b >> c;

    int x=a,y=c/2;

    while(x&&2*x+y>b){
        x--;
    }

    while(y&&2*x+y>b){
        y--;
    }

    cout<<3*(x+y)<<endl;

}
 
 
 
signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
   
 
    int t=1;
    cin>>t;
    
 
    while(t--){
       
        solve();
    
    }
 
    return 0;
}

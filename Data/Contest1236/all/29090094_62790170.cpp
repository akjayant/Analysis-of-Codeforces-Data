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

int power(int x, unsigned int y, int p) 
{ 
    int res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
}

void solve(){
    int n,m;
    cin>>n>>m;


    int pw=power(2,m,M);

    pw=(pw-1+M)%M;

    int ans=power(pw,n,M);

    cout<<ans;

    


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

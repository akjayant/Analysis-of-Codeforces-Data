#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

void solve()
{
  int n;
    cin >> n;
    
  vector< vector<int> > A(n);
 
  int flag=1;  
    
    
  for(int j=1;j<=n;j++)
  {
      flag^=1;
      
  for(int i=(n*(j-1))+1;i<=n*j;i++)
  {
     if(flag == 0) A[i-(n*(j-1))-1].pb(i);  
     else A[(n*j-i)].pb(i); 
  }
   
  }
    
  f(i,n)
  {
    for(auto x : A[i]) cout << x <<" ";
      cout<<endl;
  }
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}
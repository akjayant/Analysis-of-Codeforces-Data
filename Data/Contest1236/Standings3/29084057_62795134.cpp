#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1000000007;

int power(int x, int y, int p) 
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v[n];
    int cnt = 1;
    for(int i=0; i<n; i++)
    {
        if(cnt == n*n+1)break;
        if(i%2==0)
        {
            for(int j=0; j<n; j++)
            {
                v[j].push_back(cnt);
                cnt++;
            }
        }
        else
        {
            for(int j=n-1; j>=0; j--)
            {
                v[j].push_back(cnt);
                cnt++;
            }
        }
        
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
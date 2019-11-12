/* while(!cin.eof()) */
 
#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define mod (int)(1e9+7)
#define MAXI (int)(1e15+100)
#define N 100005
 
int power(int a,int m1)
{
    if(m1==0)return 1;
    else if(m1==1)return a;
    else if(m1==2)return (1LL*a*a)%mod;
    else if(m1&1)return (1LL*a*power(power(a,m1/2),2))%mod;
    else return power(power(a,m1/2),2)%mod;
}

// Driver code to test above functions
int32_t main()
{
    
 
    #ifndef ONLINE_JUDGE
    // for getting input from inpu.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //freopen("output.txt", "w", stdout);
    #endif
     
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    int ans = power(2, m) - 1;
    ans = power(ans, n);
    cout << ans;
 
    return 0;
    
} 
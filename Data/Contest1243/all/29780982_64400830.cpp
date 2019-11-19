#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
int solve(int v )
{
    int g = v;
    for(int i=2 ; i*i<=v ; i++ )
    {
        if( v%i == 0 )
        {
            g = __gcd(i,g);
            g = __gcd(v/i,g);
        }
    }
        
   return g;
}
signed main()
{
    fast;
    int n;
    cin >> n;
    
    cout << solve( n ) << "\n";  
}
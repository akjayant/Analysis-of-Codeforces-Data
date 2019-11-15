//g++  5.4.0

#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

signed main()
{
    fast;
    int t;
    cin >> t;
    while ( t-- )
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0 ; i < n  ;i++ ) cin >> a[i];
        sort( a.begin() , a.end());
        int ans = 0;
        for(int i=0 ; i<n; i++ )
        {
            ans = max( ans , min( a[i] , n-i));
        }
        cout << ans << "\n";
    }
        
}




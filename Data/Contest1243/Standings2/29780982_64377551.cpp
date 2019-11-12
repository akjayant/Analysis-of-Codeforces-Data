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
        string s , t;
        cin >> s >> t;
        
        int id1 = -1;
        int id2 = -1;
        int cnt = 0 ;
        for(int i=0; i < n ; i++ )
        {
            if( s[i] != t[i] )
            {
                cnt++;
                if( id1 == -1 ) id1 = i;
                else id2 = i;
            }
        }
        if( cnt == 0 ) cout << "Yes\n";
        else if( cnt == 2 )
        {
            swap( s[id1] , t[id2] );
            //cout << s << " " << t << "\n";
            if( s==t) cout << "Yes\n";
            else cout << "No\n";
        }
        else cout << "No\n";
    }
        
}




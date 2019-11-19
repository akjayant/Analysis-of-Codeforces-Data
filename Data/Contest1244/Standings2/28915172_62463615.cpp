#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.00000000000001
#define ld long double
#define inf 100000000
#define N 200005
    
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c,d,k;
        cin >> a  >> b >> c >> d >> k;
        int x = (a + c - 1) / c;
        int y = (b + d - 1) / d;
        if(x + y <= k)
            cout << x << " " << y;
        else
            cout << -1;
        cout << endl;
    }
    return 0;
}
 
 
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n;
        int lans = 0;
        for(int i = 0;i < n;i++)
        {
            lans += 1;
            if(s[i] == '1')
            {
                ans = max(ans,2 * lans);
            }
        }
        lans = 0;
        for(int i = n - 1;i >= 0;i--)
        {
            lans += 1;
            if(s[i] == '1')
                ans = max(ans,2 * lans);
        }
        cout << ans << endl;
    }
    return 0;
}
 
 
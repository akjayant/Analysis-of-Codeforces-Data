#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        int ans = 0;
        for(int i=1;i<=n;i++) // check if we can make an i square
        {
            int counter = 0;
            for(int j=0;j<n;j++)
            {
                if(v[j] >=i)
                    counter++;
            }
            if(counter>=i)
                ans = max(ans, i);
        }
        cout<<ans<<'\n';
    }
}
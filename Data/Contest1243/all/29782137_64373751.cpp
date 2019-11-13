#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{   
    int k;
    cin>>k;

    while(k--)
    {
        int n;
        cin>>n;

        vector < int > a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        sort(a.begin(), a.end());

        int ans = 1;
        for(int i=0;i<n;i++)
        {
            ans = max(ans, min(a[i], n-i));
        }
        cout<<ans<<endl;
    }

    return 0;
}
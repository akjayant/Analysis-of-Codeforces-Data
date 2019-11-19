#include<bits/stdc++.h>
#define int long long


using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string a;
        cin>>a;
        int mx=n;
        for (int i = 0; i < n; ++i) {
            if(a[i]=='1')
            {
                mx=max(mx,2*(i+1));
            }
        }

        reverse(a.begin(),a.end());
        for (int i = 0; i < n; ++i) {
            if(a[i]=='1')
            {
                mx=max(mx,2*(i+1));
            }
        }

        cout<<mx<<"\n";
    }
}
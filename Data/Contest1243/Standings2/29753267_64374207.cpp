#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N=2e5+5;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        reverse(a,a+n);
        int ans=-1;
        for(int i=0;i<n;i++)
            if(a[i]>=i+1)
                ans=i+1;
        cout<<ans<<'\n';
    }
    return 0;
}

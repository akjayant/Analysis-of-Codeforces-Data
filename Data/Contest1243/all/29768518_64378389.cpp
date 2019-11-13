#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll tc;
    cin>>tc;
    while (tc--)
    {
        int a[1005];
        ll n;
        cin>>n;
        //map<int,int>mp;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int mx=0,j=1;
        for (int i=n-1;i>=0;i--)
        {
            mx=max(mx,min(a[i],j));
            j++;
        }
        cout<<mx<<endl;

    }
    return 0;
}

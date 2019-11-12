using namespace std;
#include<bits/stdc++.h>
#define int long long
#define pb push_back 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second

signed main()
{
    IOS;
    int n; cin>>n;
    int a[n];
    int off = 2*n-1;
    a[0]=1;
    for (int i=1; i<n; i++)
    {
        if (i%2==1)
            a[i] = a[i-1]+off;
        else
            a[i] = a[i-1]+1;
    }

    for (int i=0; i<=n-1; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (j%2==0)
                cout<<a[j]+i<<" ";
            else
                cout<<a[j]-i<<" ";
        }

        cout<<endl;
    }


}

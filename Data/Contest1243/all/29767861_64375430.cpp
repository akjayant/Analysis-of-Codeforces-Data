#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define inf 1e9+7

int main()
{
    int q,n;
    cin>>q;
    while(q--)
    {
        cin>>n;
        int arr[n];
        int pos[n+1]={};
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            pos[arr[i]]++;
        }
        for(int i=n;i>0;i--)
        {
            pos[i-1]+=pos[i];
        }
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            if(pos[i]>=i)
            {
                ans=i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll arr[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        int mx=0;
        for(int i=0;i<=n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j]>=i)
                {
                    cnt++;
                }
            }
            if(cnt>=i)
            {
                mx=i;
            }
        }
        cout<<mx<<"\n";

    }
    return 0;
}

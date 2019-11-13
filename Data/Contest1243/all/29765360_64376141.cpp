#include <bits/stdc++.h>

using namespace std;
int t,n;
int arr[1010];
int main()
{
    cin>>t;
    while(t--)
    {
        fill(arr,arr+1005,0);
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=n-i)
            {
                cout<<n-i<<"\n";
                break;
            }
        }
    }
    return 0;
}

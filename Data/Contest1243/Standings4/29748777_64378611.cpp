#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
        int arr[n + 2];
        for(int i = 0; i<n; i++) scanf("%d",&arr[i]);
        sort(arr,arr+n);
        for(int i = arr[n-1]; i>=1; i--)
        {
            int cn = 0;
            for(int j = n-1; j>=0;j--)
            {
                if(arr[j]>=i) cn++;
                else break;
            }
            if(cn >= i)
            {
              // cout<<"an = ";
                cout<<i<<endl;
                break;
            }
        }
    }
}

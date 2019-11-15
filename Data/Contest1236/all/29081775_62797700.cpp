#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    for(long long int i=1;i<=n;i++)
    {
        for(long long int j=1;j<=n;j++)
        {
            if(j%2==0)
            {
                cout<<j*n-i+1<<" ";
            }
            else
            cout<<i+n*(j-1)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
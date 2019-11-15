#include <bits/stdc++.h>
using namespace std;

int a[305][305];

int main()
{
    int n,i,j,k=1;
    cin>>n;
    for(j=1;j<=n;j++)
        if(j%2==1)
        for(i=1;i<=n;i++)
            a[i][j]=k,k++;
    else
        for(i=n;i>=1;i--)
            a[i][j]=k,k++;
    for(i=1;i<=n;i++)
    {for(j=1;j<=n;j++)
    cout<<a[i][j]<<" ";
    cout<<'\n';
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
const ll mod=1e9+7;
using namespace std;
int a[305][305];
ll n,m;
int main() {
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        if(i%2)
        {
            for(int j=1;j<=n;j++)
            {
                a[j][i+1]=i*n+j;
            }
        }
        if(i%2==0)
        {
            for(int j=n;j>=1;j--)
            {
                a[j][i+1]=i*n+(n-j+1);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
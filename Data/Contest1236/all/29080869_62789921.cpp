#include <bits/stdc++.h>
#define maxn 300010
#define mod 1000000007
using namespace std;
typedef long long ll;
int ans[305][305];

int main()
{
    ll n;
    scanf("%lld",&n);
    int cnt = 1;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
            for(int j=0; j<n; j++)
            {
                ans[j][i] = cnt++;
            }
        else
            for(int j=n-1; j>=0; j--)
            {
                ans[j][i] = cnt++;
            }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}



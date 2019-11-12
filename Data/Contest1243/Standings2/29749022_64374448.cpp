/*
    Mbak Rose Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int arr[1010], dp[1010];
int main()
{
    int n,i,j,k,x,y,ans,m,q,curr,temp;
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            cin >> curr;
            arr[curr]++;
        }
        for(i=1000;i>0;i--)
        {
            dp[i] = dp[i+1] + arr[i];
        }
        ans = 0;
        for(i=1;i<=1000;i++)
        {
            if(dp[i] >= i)
            {
                ans = max(ans, i);
            }
        }
        printf("%d\n", ans);
    }
    return 0;

}

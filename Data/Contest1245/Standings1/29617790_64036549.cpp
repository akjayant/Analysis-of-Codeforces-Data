/// ANTI_LIGHT

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define f first
#define s second

const int maxn=1e5+100;
const int mod=1e9+7;

int a[20][20];
double dp[20][20];

main()
{

    int n=10;
    for(int i=n;i>=1;i--)
        for(int j=n;j>=1;j--)
            cin>>a[i][j];

    dp[n][n]=0;
    for(int j=n-1;j>=1;j--)
    {
        double t=0;
        for(int k=1;k<=6;k++)
        {
            if(j+k>n)
            {
                break;
            }
            t+=(1.0/6.0)*(dp[n][j+k]+1);
        }
        if(j>=5)
        {
            double num=6.0-(10.0-j);
            dp[n][j]=(t+num/6.0)/((6.0-num)/6.0);
        }
        else
            dp[n][j]=t;

    }
    for(int i=n-1;i>=1;i--)
    {
        if(i%2==0)
        {
            for(int j=n;j>=1;j--)
            {
               for(int k=1;k<=6;k++)
               {
                   if(j+k>n)
                   {
                       int tgx=i+1;
                       int tgy=n-((j+k)-n)+1;
                       dp[i][j]+=(1.0/6.0)*(min(dp[tgx][tgy],dp[tgx+a[tgx][tgy]][tgy])+1);
                   }
                   else
                   {
                       int tgx=i;
                       int tgy=j+k;
                       dp[i][j]+=(1.0/6.0)*(min(dp[tgx][tgy],dp[tgx+a[tgx][tgy]][tgy])+1);
                   }
               }
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=6;k++)
                {
                    if(j-k<1)
                    {
                        int tgx=i+1;
                        int tgy=1+k-j;
                        dp[i][j]+=(1.0/6.0)*(min(dp[tgx][tgy],dp[tgx+a[tgx][tgy]][tgy])+1);
                    }
                    else
                    {
                        int tgx=i;
                        int tgy=j-k;
                        dp[i][j]+=(1.0/6.0)*(min(dp[tgx][tgy],dp[tgx+a[tgx][tgy]][tgy])+1);
                    }
                }
            }
        }
    }

    cout<<setprecision(8)<<dp[1][n];
    return 0;
}

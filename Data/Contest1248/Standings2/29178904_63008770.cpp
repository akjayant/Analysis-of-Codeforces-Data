#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
char s[maxn];
int dp[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);    
    int num1 = 0,num2 = 0;
    for(int i = 1;i<=n;i++)
    {
        if(s[i] == '(')num1++;
        else num2++;
    }
    // cout<<" num1 = "<<num1<<" num2 = "<<num2<<endl;
    if(num1 != num2)
    {
        printf("0\n1 1\n");
        return 0;
    }
    int ans = 0;
    int l,r;
    for(int i = 1;i<=n;i++)
    {
        for(int j = i;j<=n;j++)
        {
            // cout<<" i ="<<i<<" j = "<<j<<endl;
            swap(s[i],s[j]);
            dp[0] =0;
            int minx = 10000;
            int num = 0;
            for(int k = 1;k<=n;k++)
            {
                // cout<<" k  "<<k<<endl;
                if(s[k] == '(')
                {
                    dp[k] = dp[k-1] + 1;
                }
                else dp[k] = dp[k - 1] - 1;
                if(dp[k]<minx)
                {
                    minx = dp[k];
                    num  = 1;
                }
                else if(dp[k] == minx)
                {
                    num ++;
                }
            }
            // cout<<" i ="<<i<<" j = "<<j<<" minx = "<<minx<<endl;
            if(num >ans)
            {
                ans = num;
                l = i;
                r = j;
            }
            swap(s[i],s[j]);
        }
    }
    printf("%d\n%d %d\n",ans,l,r);
}
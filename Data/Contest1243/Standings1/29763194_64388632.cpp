#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=55;
char s[2][maxn];
bool check1(int n)
{
    int vis[28];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<2;i++)
        for(int j=1;j<=n;j++)
            vis[s[i][j]-'a']++;
    for(int i=0;i<26;i++)
        if(vis[i]%2)
            return 0;
    return 1;
}
int ans[maxn*2][2];
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n;scanf("%d",&n);
        scanf("%s%s",s[0]+1,s[1]+1);
        if(check1(n)==0)
            printf("No\n");
        else
        {
            int len=0;
            for(int i=1;i<=n;i++)
            {
                if(s[0][i]!=s[1][i])
                {
                    for(int j=i+1;j<=n;j++)
                    {
                        if(s[1][j]==s[0][i])
                        {
                            ans[++len][0]=j;
                            ans[len][1]=j;
                            swap(s[0][j],s[1][j]);
                            break;
                        }
                    }
                    for(int j=i+1;j<=n;j++)
                    {
                        if(s[0][i]==s[0][j])
                        {
                            ans[++len][0]=j;
                            ans[len][1]=i;
                            swap(s[0][j],s[1][i]);
                            break;
                        }
                    }
                }
            }
            printf("Yes\n");
            printf("%d\n",len);
            for(int i=1;i<=len;i++)
                printf("%d %d\n",ans[i][0],ans[i][1]);
        }
    }
    return 0;
}

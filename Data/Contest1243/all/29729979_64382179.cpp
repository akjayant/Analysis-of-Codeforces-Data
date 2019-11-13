#include<bits/stdc++.h>
using namespace std;
int k,n;
char s[10010],t[10010];
int main()
{
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&n);
        scanf("%s",s);
        scanf("%s",t);
        int cnt=0;
        int pos1=-1,pos2=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                if(pos1==-1)
                {
                    pos1=i;
                }
                else
                {
                    pos2=i;
                }
                cnt++;
            }
        }
        if(cnt!=0&&cnt!=2)
        {
            printf("No\n");
            continue;
        }
        if(cnt==2)
        {
            if(s[pos1]==s[pos2]&&t[pos1]==t[pos2])
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
            continue;
        }
        printf("Yes\n");
    }
}
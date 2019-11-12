#include<bits/stdc++.h>
using namespace std;
int k,n,num[30],pos[110][2];
char s[110],t[110];
int main()
{
    scanf("%d",&k);
    while(k--)
    {
        for(int i=0;i<26;i++)
        {
            num[i]=0;
        }
        scanf("%d",&n);
        scanf("%s",s);
        scanf("%s",t);
        int cnt=0,ans=0;
        for(int i=0;i<n;i++)
        {
            num[s[i]-'a']++;
            num[t[i]-'a']++;
            if(s[i]!=t[i])
            {
                cnt++;
            }
        }
        int tt=0;
        for(int i=0;i<26;i++)
        {
            if(num[i]%2==1)
            {
                tt=1;
            }
        }
        if(tt==1)
        {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
        tt=0;
        for(int i=0;i<n;i++)
        {
            tt=0;
            for(int j=i;j<n;j++)
            {
                if(s[i]==t[j]&&tt==0)
                {
                    tt=1;
                    pos[ans][0]=j;
                    pos[ans][1]=j;
                    ans++;
                    int temp=s[j];
                    s[j]=t[j];
                    t[j]=temp;
                }
            }
            tt=0;
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j]&&tt==0)
                {
                    tt=1;
                    pos[ans][0]=j;
                    pos[ans][1]=i;
                    ans++;
                    int temp=t[i];
                    t[i]=s[j];
                    s[j]=temp;
                }
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<ans;i++)
        {
            printf("%d %d\n",pos[i][0]+1,pos[i][1]+1);
        }
    }
}
#include<bits/stdc++.h>

using namespace std;

char s[200];
char ans[200];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,a,b,c;
        scanf("%d%d%d%d",&n,&a,&b,&c);
        for(int i=0;i<n;i++)
        {
            scanf(" %c",&s[i]);
        }
        int scores=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')
            {
                if(b>0)
                {
                    b--;
                    ans[i]='P';
                    scores++;
                }
            }
            else if(s[i]=='P')
            {
                if(c>0)
                {
                    c--;
                    ans[i]='S';
                    scores++;
                }
            }
            else
            {
                if(a>0)
                {
                    a--;
                    ans[i]='R';
                    scores++;
                }
            }
        }
        if(scores>=(n+1)/2)
        {
            for(int i=0;i<n;i++)
            {
                if(ans[i]!='\0')
                {
                    continue;
                }
                if(a>0)
                {
                    a--;
                    ans[i]='R';
                }
                else if(b>0)
                {
                    b--;
                    ans[i]='P';
                }
                else
                {
                    c--;
                    ans[i]='S';
                }
            }
            printf("YES\n");
            for(int i=0;i<n;i++)
            {
                printf("%c",ans[i]);
            }
            printf("\n");
        }
        else
        {
            printf("NO\n");
        }
        for(int i=0;i<n;i++)
        {
            ans[i]='\0';
        }


    }
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a,b,c;
char s[150];
char t[150];
int cnt;

int main()
{
    int T;cin>>T;
    while(T--)
    {
        memset(t,0,sizeof t);
        cnt=0;
        cin>>n;
        cin>>a>>b>>c;
        scanf("%s",s+1);
        for(int i=1;i<=n;++i)
        {
            if(s[i]=='P'&&c)
            {
                c--;
                t[i]='S';
                cnt++;
            }
            if(s[i]=='R'&&b)
            {
                b--;
                t[i]='P';
                cnt++;
            }
            if(s[i]=='S'&&a)
            {
                a--;
                t[i]='R';
                cnt++;
            }
        }
        if(cnt<(n+1)/2){puts("NO");continue;}
        for(int i=1;i<=n;++i)
        {
            if(t[i]==0&&c)
            {
                c--;
                t[i]='S';
            }
            if(t[i]==0&&b)
            {
                b--;
                t[i]='P';
            }
            if(t[i]==0&&a)
            {
                a--;
                t[i]='R';
            }
        }
        printf("YES\n");
        printf("%s\n",t+1);
    }
    return 0;
}

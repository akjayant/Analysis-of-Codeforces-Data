#include <bits/stdc++.h>
#define ll long long

using namespace std;
char Bob[110],Alice[110];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int i,j;
    int t,n,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>c;
        cin>>Bob;
        memset(Alice,0,sizeof(Alice));
        int cnt=0;
        for(i=0;Bob[i];i++)
        {
            if(Bob[i]=='R')
            {
                if(b)
                    Alice[i]='P',b--,cnt++;
            }
            else if(Bob[i]=='P')
            {
                if(c)
                    Alice[i]='S',c--,cnt++;
            }
            else
            {
                if(a)
                    Alice[i]='R',a--,cnt++;
            }
        }        
        if(cnt>=(n+1)/2)
        {
            puts("YES");
            for(i=0;Bob[i];i++)
                if(Alice[i]==0)
                {
                    if(a)
                        Alice[i]='R',a--;
                    else if(b)
                        Alice[i]='P',b--;
                    else
                        Alice[i]='S',c--;
                }
            for(i=0;Bob[i];i++)
                printf("%c",Alice[i]);
            puts("");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}

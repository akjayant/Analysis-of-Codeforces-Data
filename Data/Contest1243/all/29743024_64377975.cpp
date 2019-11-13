#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7fffffff,MAXM=2e6+10,MAXN=2e5+10;

int a[MAXN];
char s[MAXN],t[MAXN];

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        scanf("%s",t+1);
        int a1=0,b1=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]!=t[i])
            {
                if(!a1)a1=i;
                else if(!b1)b1=i;
                else a1=-1;
            }
        }
        if(a1==-1)
        {
            puts("No");
            continue;
        }
        if(!a1&&!b1)
        {
            puts("Yes");
            continue;
        }
        if(a1&&!b1)
        {
            puts("No");
            continue;
        }
        if(s[a1]==s[b1]&&t[b1]==t[a1])
        {
            puts("Yes");
            continue;
        }
        puts("No");
    }
    return 0;
}

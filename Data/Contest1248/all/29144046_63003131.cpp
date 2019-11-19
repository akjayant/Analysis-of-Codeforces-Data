#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300050;
int n;
char s[N];
int Lcnt,Rcnt;
int x,y;
int sta[N<<1];
int ans;

inline int work()
{
    int top=0;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='(')sta[++top]=-1;
        else
        {
            if(sta[top]==-1)top--;
            else sta[++top]=i;
        }
    }
    while(sta[top]==-1)top--;
    return sta[top];
}
inline int solve(int pos)
{
    int ret=0,top=0;
    for(int i=1;i<=n;++i)
    {
        int now=i+pos;
        if(now>n)now-=n;
        if(s[now]=='(')top++;
        else top--;
        if(top==0)ret++;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='(')Lcnt++;
        else Rcnt++;
    }
    if(Lcnt!=Rcnt){puts("0");puts("1 1");return 0;}
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<i;++j)
        {
            swap(s[i],s[j]);
            int pos=work();
            int tmp=solve(pos);
            if(tmp>ans)
            {
                ans=tmp;
                y=i,x=j;
            }
            swap(s[i],s[j]);
        }
    }
    printf("%d\n",ans);
    printf("%d %d\n",x,y);
    return 0;
}

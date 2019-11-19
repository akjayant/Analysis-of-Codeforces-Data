#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define ha 1000000007
#define ui unsigned int
#define pii pair<int,int>
#define pid pair<int,double>

using namespace std;

inline int read()
{
    char ch=getchar(); int f=1,x=0;
    while (ch<'0' || ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
    while (ch>='0' && ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
    return f*x;
}

int n,ans,l,r;
char s[505];

inline int work()
{
    int mn=n,mni,cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (s[i]=='(') cnt++;
        else cnt--;
        if (s[i]==')') continue;
        if (cnt<mn) mn=cnt,mni=i;
    }
    cnt=0; int res=0;
    for (int i=1,j=mni;i<=n;i++,j=j==n ? 1 : j+1)
    {
        if (s[j]=='(') cnt++;
        else
        {
            cnt--;
            if (!cnt) res++;
        }
    }
    return res;
}

signed main()
{
    n=read();
    scanf("%s",s+1);
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (s[i]=='(') cnt++;
        else cnt--;
    }
    if (cnt) return !printf("0\n1 1");
    ans=work();
    l=r=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            swap(s[i],s[j]);
            int res=work();
            if (res>ans)
            {
                ans=res;
                l=i,r=j;
            }
            swap(s[i],s[j]);
        }
    }
    return !printf("%d\n%d %d",ans,l,r);
}
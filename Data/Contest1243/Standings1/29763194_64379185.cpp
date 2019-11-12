#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=10005;
char s[2][maxn];
bool check1(int n)
{
    for(int i=1;i<=n;i++)
        if(s[0][i]!=s[1][i])
            return 0;
    return 1;
}
int a[maxn];
bool check2(int n)
{
    int len=0;
    for(int i=1;i<=n;i++)
    {
        if(s[0][i]!=s[1][i])
            a[++len]=i;
    }
    return len==2&&s[1][a[1]]==s[1][a[2]]&&s[0][a[1]]==s[0][a[2]];
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n;scanf("%d",&n);
        scanf("%s%s",s[0]+1,s[1]+1);
        if(check1(n)||check2(n))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

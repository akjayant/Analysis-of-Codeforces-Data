#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define maxn 1010
typedef long long ll;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T,n;
char s[maxn];
int main()
{
    T=read();
    while(T--)
    {
        n=read();
        scanf("%s",s+1);
        int ans=n;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='1')
            {
                ans=max(ans,2*max(i,n-i+1));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define DEBUG
using namespace std;
const int maxn=200010;
const int mod=100007;
const int N = 500 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const double PI = acos(-1);

int n,cnt,ans,flag;
ll m;
inline int read()
{
    register int c = getchar(), fg = 1, sum = 0;
    while(c > '9' || c < '0' )
    {
        if(c == '-')fg = -1;
        c = getchar();
    }
    while(c <= '9' && c >= '0')
    {
        sum = sum *10 + c - '0';
        c = getchar();
    }
    return fg * sum;
}
int num[maxn];
void init()
{
    for(int i=0;i<n;i++)
        num[i]=read();
    sort(num,num+n);
}

void go()
{
    int x=0,y=n-1;
    while(m&&num[x]!=num[y])
    {
        if(x+1<n-y)
        {
            ll s=(x+1)*(ll)(num[x+1]-num[x]);
            if(s<=m)
            {
                m-=s;
                x++;
            }
            else
            {
                num[x]+=m/(x+1);
                break;
            }
        }
        else
        {
            ll s=(n-y)*(ll)(num[y]-num[y-1]);
            if(s<=m)
            {
                m-=s;
                y--;
            }
            else
            {
                num[y]-=m/(n-y);
                break;
            }
        }
    }
    printf("%d\n",num[y]-num[x]);
}
int main()
{
    while(~scanf("%d%lld",&n,&m))
    {
        init();
        go();
    }
}

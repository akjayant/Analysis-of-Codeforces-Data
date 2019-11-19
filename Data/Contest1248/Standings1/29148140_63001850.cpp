//D1. The World Is Just a Programming Task (Easy Version)
//By: Terrasse
//2019年 10月 20日 星期日 17:55:47 CST

#include<iostream>
#define MAXN 555
#define INF 0x3f3f3f3f
//#define swap(x,y) ((x)^=(y)^=(x)^=(y))
using namespace std;
int n=0;
char c[MAXN];
bool a[MAXN];
inline int calc();
int main()
{
    register int i=0,j=0,k=0,ans1=0,ans2=0,cnt=0,maxb=-INF,btf=0;
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>c+1;
    for(i=1;i<=n;++i)
    {
        a[i]=(c[i]=='(');
    }
    for(i=1;i<=n;++i)
    {
        if(a[i])
        {
            ++cnt;
        }
    }
    if(cnt*2!=n)
    {
        cout<<'0'<<endl<<"1 1"<<endl;
        return 0;
    }
    for(i=1;i<=n;++i)
    {
        for(j=i;j<=n;++j)
        {
            swap(a[i],a[j]);
            btf=calc();
            if(maxb<btf)
            {
                maxb=btf;
                ans1=i;
                ans2=j;
            }
            swap(a[i],a[j]);
        }
    }
    cout<<maxb<<endl<<ans1<<' '<<ans2<<endl;
    return 0;
}
inline int calc()
{
    register int i=0,minc=INF,cnt=0,ret=0,p=0;
    for(i=1;i<=n;++i)
    {
        if(a[i])
        {
            if(minc>++cnt)
            {
                minc=cnt;
                p=i;
            }
        }
        else
        {
            --cnt;
        }
    }
    for(cnt=0,i=1;i<=n;++i)
    {
        if(a[p])
        {
            ++cnt;
        }
        else
        {
            if(--cnt==0)
            {
                ++ret;
            }
        }
        if(p==n)
        {
            p=1;
        }
        else
        {
            ++p;
        }
    }
    return ret;
}

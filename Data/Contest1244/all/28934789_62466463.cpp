#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    int T=read();
    while(T--)
    {
        int a=read(),b=read(),c=read(),d=read(),k=read();
        int ans1=(a-1)/c+1,ans2=(b-1)/d+1;
        if(ans1+ans2>k)  puts("-1");
        else             cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9') {if(c=='-')flag=1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x+(x<<2)<<1)+ c-'0';c=getchar();}
    return flag?-x:x;
}
int main()
{
	int n=read();
	while(n--)
	{
		int a=read(),b=read(),c=read(),d=read(),k=read(),x1=0,y1=0;
	while(a>0) a-=c,++x1;
	while(b>0) b-=d,++y1;
	if(x1+y1<=k) printf("%d %d\n",x1,y1);
	else printf("-1\n");
	}
	
}

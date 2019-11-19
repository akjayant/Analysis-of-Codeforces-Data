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
	int T=read();
	while(T--)
	{
		int n=read(),ans=0;
		string s;cin>>s;
		for(int i=0;i<n;++i) if(s[i]=='1') ans=max(ans,i+2+max(i,n-i-1));
		for(int i=n-1;i>=0;--i) if(s[i]=='1') ans=max(ans,n-i+1+max(n-i-1,i));
		ans=max(ans,n);
		printf("%d\n",ans);
	}
}

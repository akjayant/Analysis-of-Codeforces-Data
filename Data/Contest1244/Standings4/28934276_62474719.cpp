#include<iostream>
#include<cstdio>

#define rd(x) x=read()

using namespace std;

int t;
int n;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

signed main()
{
	rd(t);
	for(int cas=1;cas<=t;cas++)
	{
		int x;rd(x);
		string s;cin>>s;int l=s.length(),p1=-1,p2=-1;
		for(int i=0;i<l;i++)if(s[i]=='1'){p1=l-i;break;}
		for(int i=l-1;i>=0;i--)if(s[i]=='1'){p2=i+1;break;}
		if(p1==-1&&p2==-1)cout<<l<<endl;
		else cout<<2*max(p1,p2)<<endl;
	}
	
	
	return 0;
}

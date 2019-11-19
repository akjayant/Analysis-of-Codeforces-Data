#include<iostream>
#include<cstdio>

#define rd(x) x=read()

using namespace std;

int t;

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
	for(int cas=0;cas<t;cas++)
	{
		int a,b,c,d,k;
		rd(a),rd(b),rd(c),rd(d),rd(k);
		if((b-1)/d+(a-1)/c+2>k){cout<<-1<<endl;continue;}
		cout<<(a-1)/c+1<<' '<<(b-1)/d+1<<endl;
	}
	
	return 0;
}

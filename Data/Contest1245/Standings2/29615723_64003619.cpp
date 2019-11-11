#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int T;scanf("%d",&T);
	char s[200];int t[200];
	while(T--)
	{
		memset(t,0,sizeof(t));
		int n,a,b,c,x=0,y=0,z=0;scanf("%d %d %d %d %s",&n,&a,&b,&c,s);
		for(int i=0;i<n;++i) 
		{
			if(s[i]=='S') ++x;
			if(s[i]=='R') ++y;
			if(s[i]=='P') ++z;
		};
		int res=min(a,x)+min(b,y)+min(c,z);
		if(res<((n+1)/2)) printf("NO\n"); 
		else
		{
			printf("YES\n");
			for(int i=0;i<n;++i)
			{
				if(s[i]=='S'&&a) --a,t[i]=1;
				if(s[i]=='R'&&b) --b,t[i]=2;
				if(s[i]=='P'&&c) --c,t[i]=3;
			};
			for(int i=0;i<n;++i)
				if(!t[i])
				{
					if(a) t[i]=1,--a;
					else if(b) t[i]=2,--b;
					else if(c) t[i]=3,--c;
				};
			for(int i=0;i<n;++i) 
			{
				if(t[i]==1) printf("R");
				if(t[i]==2) printf("P");
				if(t[i]==3) printf("S");
			};
			puts("");
		};
	}
	return 0;
}
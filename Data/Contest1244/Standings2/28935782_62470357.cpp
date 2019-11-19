/* LittleFall : Hello! */
#include <bits/stdc++.h>
using namespace std; using ll = long long; inline int read();
const int M = 1024, MOD = 1000000007;

char save[M];
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
    #endif

	int t = read();
	while(t--)
	{
		int n = read();
		scanf("%s",save+1);
		int mi = -1, ma = -1;
		for(int i=1; i<=n; ++i)
		{
			if(save[i]=='1')
			{
				if(mi==-1)
					mi = i;
				ma = i;
			}
		}
		if(mi==-1)
		{
			printf("%d\n",n);
		}
		else
		{
			printf("%d\n",max(ma*2,(n-mi+1)*2) );
		}
	}

    return 0;
}


inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
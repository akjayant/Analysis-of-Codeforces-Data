//ѹ�пδ�
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=3e2+10;
int read(){int sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
int R(){char ccc=getchar();while(ccc<'0'||ccc>'9') ccc=getchar();return ccc-'0';}
int ans[MAXN][MAXN];
int main()
{
//	freopen("123.in","r",stdin);
//	freopen("123.out","w",stdout);
	int n=read();
	int k=1;
	bool flag=true;
	for(int i=1;i<=n;i++) 
	{
		if(flag)
		{
			for(int j=1;j<=n;j++)
				ans[j][i]=k++;
			flag=false;
		}
		else
		{
			for(int j=n;j>=1;j--)
				ans[j][i]=k++;
			flag=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}

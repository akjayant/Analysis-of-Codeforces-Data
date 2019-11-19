/* LittleFall : Hello! */
#include <bits/stdc++.h>
using namespace std; using ll = long long; inline int read();
const int M = 128, MOD = 1000000007;

int save[M][M];
int pos[M][M];
int trans[M]; //传送门
double dp[M]; 
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
    #endif

	for(int i=1; i<=10; ++i)
		for(int j=1; j<=10; ++j)
			save[i][j] = read();

	int px = 0;
	for(int i=10; i>=1; --i)
	{
		if(!(i&1)) for(int j=1; j<=10; ++j)
			pos[i][j] = ++px;
		else for(int j=10; j>=1; --j)
			pos[i][j] = ++px;
	}
	for(int i=1; i<=10; ++i)
		for(int j=1; j<=10; ++j)
			if(save[i][j])
				trans[pos[i][j]] = pos[i-save[i][j]][j];

	// for(int i=1; i<=10; ++i)
	// {
	// 	for(int j=1; j<=10; ++j)
	// 	{
	// 		printf("%d ",pos[i][j] );
	// 	}
	// 	printf("\n");
	// }
	// for(int i=1; i<=100; ++i) if(trans[i])
	// 	printf("%d %d\n",i,trans[i] );

	dp[100] = 0; //最小期望步数
	dp[99] = dp[98] = dp[97] = dp[96] = dp[95] = 6;
	for(int i=94; i>=1; --i)
	{
		for(int j=1; j<=6; ++j)
		{
			double x = dp[i+j];
			if(trans[i+j]) x = min(x, dp[trans[i+j]]);
			dp[i] += x;
		}
		dp[i] = dp[i]/6+1;
		//printf("%d %.3f\n",i, dp[i] );
	}
	printf("%.8f\n",dp[1] );

    return 0;
}


inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
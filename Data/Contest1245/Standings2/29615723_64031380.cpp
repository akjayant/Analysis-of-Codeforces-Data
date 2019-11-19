#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=10;
vector<int> ld[N*N+10];
double f[N*N+10][2];

int id(int x,int y)
{
	if(x&1) return 10*x+10-y;
	else return 10*x+y+1;
}

int main()
{
	f[1][0]=f[1][1]=0;for(int i=2;i<=7;++i) f[i][0]=f[i][1]=6;
	// for(int i=0;i<10;++i)
	// {
	// 	for(int j=0;j<10;++j) printf("%d ",id(i,j));
	// 	puts("");
	// };
	// puts("");
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
		{
			int h;scanf("%d",&h);if(!h) continue;
			ld[id(i,j)].push_back(id(i-h,j));
			// printf("%d %d\n",id(i,j),id(i-h,j));
		};
	for(int i=8;i<=100;++i)
	{
		double s=0;for(int j=1;j<=6;++j) s+=f[i-j][1];
		f[i][1]=f[i][0]=s/6+1;
		for(int j=0;j<ld[i].size();++j) f[i][1]=min(f[i][1],f[ld[i][j]][0]);
	};
	printf("%.10f\n",f[100][1]);
	return 0;
}
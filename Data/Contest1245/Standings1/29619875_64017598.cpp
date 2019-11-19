#include<bits/stdc++.h>
using namespace std;
int g[11][11];
double f[11][11];
inline void go(int &x,int &y,int step)
{
	while(step--)
	{
		if(x&1)
		{
			if(y==1)
				x--;
			else
				y--;
		}
		else
		{
			if(y==10)
				x--;
			else
				y++;
		}
	}
}
int main()
{
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
			scanf("%d",&g[i][j]);
	f[1][1]=0;
	f[1][2]=f[1][3]=f[1][4]=f[1][5]=f[1][6]=6;
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
		{
			if(i==1&&j<=6)
				continue;
			int x=i,y=j;
			if(!(x&1))
				y=11-j;
			for(int num=1;num<=6;num++)
			{
				int xx=x,yy=y;
				go(xx,yy,num);
				if(g[xx][yy])
					f[x][y]+=min(f[xx][yy],f[xx-g[xx][yy]][yy]);
				else
					f[x][y]+=f[xx][yy];
			}
			f[x][y]/=6.0;
			f[x][y]+=1.0;
		}
	printf("%.10lf\n",f[10][1]);
	return 0;
}
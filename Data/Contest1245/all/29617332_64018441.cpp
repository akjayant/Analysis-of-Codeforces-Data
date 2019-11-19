#include<bits/stdc++.h>

using namespace std;
const int N=21;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int g[N][N];
double f[N][N];
pair<int,int> cal_nxt(pair<int,int> pos)
{
	int x=pos.fi,y=pos.se;
	int dir;
	if (x&1) dir=-1;
	else dir=1;
	if (y+dir>10||y+dir<1) x--;
	else y+=dir;
	return mp(x,y); 
}
pair<int,int> cal_nxtk(pair<int,int>pos, int k)
{
	for (int i=1;i<=k;i++)
		pos=cal_nxt(pos);
	return pos;	
}
int main()
{
	for (int i=1;i<=10;i++)
		for (int j=1;j<=10;j++)
		{
			int x;
			scanf("%d",&g[i][j]);
		}
	f[1][1]=0;
	f[1][2]=6;
	f[1][3]=f[1][4]=f[1][5]=f[1][6]=f[1][7]=6;
	for (int i=1;i<=10;i++)
	{
		int beg=1,ff=1;
		if (i&1) beg=1,ff=1;
		else beg=10,ff=-1;
		for (int j=beg;j>=1&&j<=10;j+=ff)
		{
			if (i==1&&j<=7) continue;
			pair<int,int> pos=mp(i,j),nxt_pos;
			double res=0;
			for (int k=1;k<=6;k++)
			{
				nxt_pos=cal_nxtk(pos,k);
				int x=nxt_pos.fi, y=nxt_pos.se;
				if (!g[x][y]) res+=1+f[x][y];
				else res+=1+min(f[x][y],f[x-g[x][y]][y]);
			}
			f[i][j]=res/6.0;
		}
	}
	printf("%.15f\n",f[10][1]);
	return 0;
}
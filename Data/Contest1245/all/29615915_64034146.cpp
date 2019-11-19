#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <utility>
using namespace std;
double e[12][12][2];
typedef pair<int,int> pi;
inline pi nxt(pi x)
{
	if (x.first&1) x.second==1? --x.first:--x.second;
	else x.second==10? --x.first:++x.second;
	return x;
}
inline pi pre(pi x)
{
	if (x.first&1) x.second==10? ++x.first:++x.second;
	else x.second==1? ++x.first:--x.second;
	return x;	
}
int f[12][12];
int main()
{
	e[1][1][0]=e[1][1][1]=0;
	for (int i=2;i<=6;i++) e[1][i][0]=e[1][i][1]=6;
	for (int i=7;i<=10;i++)
	{
		for (int j=1;j<=6;j++)
			e[1][i][0]+=e[1][i-j][0];	
		e[1][i][0]/=6;	
		e[1][i][0]+=1;
		e[1][i][1]=e[1][i][0];
	}
	for (int i=1;i<=10;i++)
		for (int j=1;j<=10;j++)
			scanf("%d",&f[i][j]);
	pi cur=make_pair(2,10);
	while (cur!=make_pair(11,1))
	{
		pi t=cur;
		for (int i=1;i<=6;i++)
		{
			t=nxt(t);
			e[cur.first][cur.second][0]+=min(e[t.first][t.second][0],e[t.first][t.second][1]);
		}
		e[cur.first][cur.second][0]/=6;
		e[cur.first][cur.second][0]+=1;
		if (f[cur.first][cur.second]) e[cur.first][cur.second][1]=e[cur.first-f[cur.first][cur.second]][cur.second][0];
		else e[cur.first][cur.second][1]=1e18;
		cur=pre(cur);
	}
	printf("%.10f",min(e[10][1][0],e[10][1][1]));
	return 0;
}

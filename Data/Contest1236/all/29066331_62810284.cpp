#include<cstdio>
#include<vector>
using namespace std;
vector<int> vx[100005],vy[100005];
int n,m,k,x,y,f,lx,rx,ly,ry,ans;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&y,&x);
		vx[x].push_back(y);
		vy[y].push_back(x);
	}
	long long ge=1LL*n*m-k,sum=0;
	bool bo=true;
	x=1,y=1,f=1;
	lx=1,rx=m;
	ly=1,ry=n;
	while(bo&&lx<=rx&&ly<=ry)
	{
		switch(f)
		{
			case 1:
				ans=rx+1;
				for(int i=0;i!=vy[y].size();i++)
				{
				//	printf("(%d %d %d)->%d\n",x,y,f,vy[y][i]);
					if(vy[y][i]>=x)
						ans=min(ans,vy[y][i]);
				}
				if(ans==x)
				{
					bo=false;
					break;
				}
				else
				{
					ans--;
//					printf("%d %d %d %d (%d %d %d)->",lx,rx,ly,ry,x,y,f);
					sum+=ans-x+1;
					x=ans;
					y=y+1;
					ly=y;
					rx=x;
					f=2;
//					printf("(%d %d %d)\n",x,y,f);
				}
				break;
			case 2:
				ans=ry+1;
				for(int i=0;i!=vx[x].size();i++)
				{
					if(vx[x][i]>=y)
						ans=min(ans,vx[x][i]);
				}
				if(ans==y)
				{
					bo=false;
					break;
				}
				else
				{
					ans--;
//					printf("%d %d %d %d (%d %d %d)->",lx,rx,ly,ry,x,y,f);
					sum+=ans-y+1;
					y=ans;
					x=x-1;
					rx=x;
					ry=y;
					f=3;
//					printf("(%d %d %d)\n",x,y,f);
				}
				break;
			case 3:
				ans=lx-1;
				for(int i=0;i!=vy[y].size();i++)
				{
//					printf("%d\n",vy[y][i]);
					if(vy[y][i]<=x)
						ans=max(ans,vy[y][i]);
				}
				if(ans==x)
				{
					bo=false;
					break;
				}
				else
				{
					ans++;
//					printf("%d %d %d %d (%d %d %d)->",lx,rx,ly,ry,x,y,f);
					sum+=x-ans+1;
					x=ans;
					y=y-1;
					lx=x;
					ry=y;
					f=4;
//					printf("(%d %d %d)\n",x,y,f);
				}
				break;
			case 4:
				ans=ly-1;
				for(int i=0;i!=vx[x].size();i++)
				{
					if(vx[x][i]<=y)
						ans=max(ans,vx[x][i]);
				}
				if(ans==y)
				{
					bo=false;
					break;
				}
				else
				{
					ans++;
//					printf("%d %d %d %d (%d %d %d)->",lx,rx,ly,ry,x,y,f);
					sum+=y-ans+1;
					y=ans;
					x=x+1;
					lx=x;
					ly=y;
					f=1;
//					printf("(%d %d %d)\n",x,y,f);
				}
				break;
		}
	}
	if(sum==ge)
		printf("Yes");
	else
		printf("No");
}
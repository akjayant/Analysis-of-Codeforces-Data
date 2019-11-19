#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long 
using namespace std;
const int M = 250000;
LL k;
int n,m;
struct vv
{
	int a,c;
} t[M], w[M];
bool cmp(vv a,vv b){return a.a<b.a;}

int main()
{
	cin>> n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&t[i].a);
	sort(t+1,t+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(t[i].a==t[i-1].a) w[m].c++;
		else 
		{
			w[++m]=t[i];
			w[m].c=1;
		}
	}
	int l=1,r=m;
	while(k && l!=r)
	{
		if(w[r].c<w[l].c) 
		{
			int v=w[r].a-w[r-1].a;
			if((LL)v*w[r].c>k) 
			{
				int o=k/w[r].c;
				printf("%d",w[r].a-w[l].a-o);
				return 0;
			}
			k-=(LL)v*w[r].c;
			w[r-1].c+=w[r].c;
			r-=1;
		}
		else 
		{
			int v=w[l+1].a-w[l].a;
			if((LL)v*w[l].c>k) 
			{
				int o=k/w[l].c;
				printf("%d",w[r].a-w[l].a-o);
				return 0;
			}
			k-=(LL)v*w[l].c;
			w[l+1].c+=w[l].c;
			l+=1;
		}
	}
	
	printf("%d",w[r].a-w[l].a);
}
#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

using ll = long long;

const int NMAX = 2123;

struct Vr
{
	ll x,y;
	ll c,k;
	Vr * up;
	int hl=1;
	Vr * upup()
	{
		if(up==0) return this;
		if(up==this) return this;
		up=up->upup();
		return up;
	}
};
struct Hr
{
	int a,b;
	ll cost;
	bool out;
	bool operator < (Hr d)
	{
		return cost < d.cost;
	}
};

int n;
Vr vr [NMAX];
Hr hr [NMAX*NMAX];
int hrlen;

int main()
{

	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&(vr[i].x),&(vr[i].y));
	for(int i=1;i<=n;i++)
		scanf("%lld",&(vr[i].c));
	for(int i=1;i<=n;i++)
		scanf("%lld",&(vr[i].k));
	for(int i=1;i<=n;i++)
		hr[hrlen++]=Hr{0,i,vr[i].c};
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			hr[hrlen++]=Hr{i,j,(vr[i].k+vr[j].k) * ll(abs(vr[i].x-vr[j].x)+abs(vr[i].y-vr[j].y))};
		}
	sort(hr,hr+hrlen);
	for(int i=0;i<hrlen;i++)
	{
		Vr * a = vr[hr[i].a].upup();
		Vr * b = vr[hr[i].b].upup();
		if(a!=b)	
		{
			hr[i].out=1;
			if(a->hl == b->hl)
			{
				a->up=b;
				b->hl++;
			}
			else if(a->hl > b->hl)
			{
				b->up=a;
			}
			else a->up=b;
		}
	}
	unsigned long long out=0;
	int traf=0,dratu=0;
	for(int i=0;i<hrlen;i++)
	{
		if(hr[i].out)
		{
			out+=hr[i].cost;
			if(hr[i].a==0) traf++;
			else dratu++;
		}
	}
	printf("%llu\n%d\n",out,traf);
	for(int i=0;i<hrlen;i++)
	{
		if(hr[i].out)
		{
			if(hr[i].a==0) printf("%d ",hr[i].b);
		}
	}
	if(traf) printf("\n");
	printf("%d\n",dratu);
	for(int i=0;i<hrlen;i++)
	{
		if(hr[i].out)
		{
			if(hr[i].a==0) ;
			else printf("%d %d\n",hr[i].a,hr[i].b);
		}
	}
	return 0;
}


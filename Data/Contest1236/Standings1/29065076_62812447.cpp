#include<bits/stdc++.h>
#define mxn 1000010
#define db double
#define LL long long
#define ldb long double
#define pb push_back
#define ppb pop_back
#define pf push_front
#define pii pair<int,int> 
#define mp make_pair
#define fr first
#define sc second
#define x1 faqx1
#define y1 faqy1
#define x2 faqx2
#define y2 faqy2
using namespace std;
const int inf=1e9,mod=1e9+7;
int n,m,K,sl,fh;
set<int> a[mxn],b[mxn];
struct seg
{
	int lt;
	LL s;
}tr[mxn<<2];
#define mid ((l+r)>>1)
void upd(int x,int l,int r,int v) {tr[x].lt+=v; tr[x].s+=1ll*v*(r-l+1);}
void pushdown(int x,int l,int r)
{
	if(tr[x].lt)
	{
		upd(x<<1,l,mid,tr[x].lt);
		upd(x<<1|1,mid+1,r,tr[x].lt);
		tr[x].lt=0;
	}
}
void update(int x,int l,int r,int L,int R,int v)
{
	if(L>R||l>r) return ;
	if(L<=l&&r<=R) return upd(x,l,r,v);
	pushdown(x,l,r);
	if(L<=mid) update(x<<1,l,mid,L,R,v);
	if(R>mid) update(x<<1|1,mid+1,r,L,R,v);
	tr[x].s=tr[x<<1].s+tr[x<<1|1].s;
}
#undef mid
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int main()
{
	n=rd();m=rd();K=rd();int x,y,d,flg;
	for(int i=1;i<=K;++i)
	{
		x=rd();y=rd();
		update(1,1,n,x,x,1);
		a[x].insert(y);b[y].insert(x);
	}
	x=y=1;d=1;flg=0;
	int sx=1,sy=0,ex=n+1,ey=m+1;
	for(int p;;)
	{
		if(d==1)
		{
			p=1e9;
			if(a[x].size())
			{
				auto it=a[x].upper_bound(y);
				if(it!=a[x].end()) p=(*it)-1;
			}
			p=min(p,ey-1);
			update(1,1,n,x,x,p-y+1);
			if(y==p&&flg) break;
			else flg=0;
			ey=y=p;d=2;
		}
		else if(d==2)
		{
			p=1e9;
			if(b[y].size())
			{
				auto it=b[y].upper_bound(x);
				if(it!=b[y].end()) p=(*it)-1;
			}
			p=min(p,ex-1);
			if(x==p&&flg) break;
			update(1,1,n,x+1,p-1,1);
			ex=x=p;d=3;
		}
		else if(d==3)
		{
			p=0;
			if(a[x].size())
			{
				auto it=a[x].lower_bound(y);
				if(it!=a[x].begin()) p=(*--it)+1;
			}
			p=max(p,sy+1);
			update(1,1,n,x,x,y-p+1);
			if(y==p&&flg) break;
			sy=y=p;d=4;
		}
		else
		{
			p=0;
			if(b[y].size())
			{
				auto it=b[y].lower_bound(x);
				if(it!=b[y].begin()) p=(*--it)+1;
			}
			p=max(p,sx+1);
			if(x==p&&flg) break;
			update(1,1,n,p+1,x-1,1);
			sx=x=p;d=1;
		}
		flg=1;
	}
	if(tr[1].s==1ll*n*m) puts("Yes");
	else puts("No");
	return 0;
}
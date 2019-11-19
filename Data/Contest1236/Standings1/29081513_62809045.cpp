#include<bits/stdc++.h>
#define ll long long
#define R register
using namespace std;
const int N = 5e5+200;
template <class Ruby_Rose> inline void read(Ruby_Rose &x)
{
 	x=0;
	char ch=getchar(), w=0;
	while(!isdigit(ch))w=(ch=='-'), ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	x=w?-x:x;
}
ll sum, done;
ll n, m, k;
set <int> h[N];
set <int> w[N];
set <int> :: iterator it;
int lim[5][5];//shangxia zuoyou
int main()
{
	read(n), read(m), read(k);
	for(R int i=1, qa, qb; i<=k; i++)
	{
		read(qa), read(qb);
		h[qa].insert(qb); w[qb].insert(qa);
	}
	for(R int i=1; i<=n; i++)h[i].insert(-1), h[i].insert(m+1);
	for(R int i=1; i<=m; i++)w[i].insert(-1), w[i].insert(n+1);
	int dir=0, nowx=1, nowy=0; lim[0][0]=1, lim[0][1]=n+1; lim[1][0]=0, lim[1][1]=m+1;
	while(1)
	{
		if(dir==0)
		{
			it=h[nowx].lower_bound(nowy); int tmp=lim[1][1];
			if(it!=h[nowx].end())tmp=min(tmp, *it);
			if(tmp-1==nowy)break;
			done+=tmp-nowy-1; nowy=tmp-1; dir=(dir+1)%4; lim[1][1]=min(lim[1][1], nowy);
		}
		else if(dir==1)
		{
			it=w[nowy].lower_bound(nowx); int tmp=lim[0][1];
			if(it!=w[nowy].end())tmp=min(tmp, *it);
			if(tmp-1==nowx)break;
			done+=tmp-nowx-1; nowx=tmp-1; dir=(dir+1)%4; lim[0][1]=min(lim[0][1], nowx);
		}
		else if(dir==2)
		{
			it=h[nowx].lower_bound(nowy); int tmp=lim[1][0];
			if(it!=h[nowx].begin())
			{
				it--;
				tmp=max(tmp, *it);
			}
			if(tmp+1==nowy)break;
			done+=nowy-tmp-1; nowy=tmp+1; dir=(dir+1)%4; lim[1][0]=max(lim[1][0], nowy);
		}
		else if(dir==3)
		{
			it=w[nowy].lower_bound(nowx); int tmp=lim[0][0];
			if(it!=h[nowy].begin())
			{
				it--;
				tmp=max(tmp, *it);
			}
			if(tmp+1==nowx)break;
			done+=nowx-tmp-1; nowx=tmp+1; dir=(dir+1)%4; lim[0][0]=max(lim[0][0], nowx);
		}
//		cout<<nowx<<" "<<nowy<<" "<<dir<<" ";
//		cout<<"?\n"; 
	}
	if(done==n*m-k)
	{
		printf("Yes\n");
	}else printf("No\n");
	return 0;
}
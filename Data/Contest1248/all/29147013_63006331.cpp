//ѹ�пδ�
#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const int MAXN=1e5+10;
LL ans[MAXN],n,p,s[MAXN],k[MAXN];
priority_queue<LL>A;
priority_queue<pair<LL,LL> >B;
queue<LL> C;
int lowbit(int x){return x&(-x);}
void add(int x,int op)
{
	for(int i=x;i<MAXN;i+=lowbit(i))
		s[i]+=op;
}
bool query(int x)
{
	for(int i=x;i;i-=lowbit(i))
		if(s[i]) return true;
	return false;
}
inline LL read(){LL sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
inline char R(){char ccc=getchar();while(ccc!='('&&ccc!=')') ccc=getchar();return ccc;}
void check(LL x)
{
	while(!B.empty()&&(-B.top().first)<=x)
		A.push(-B.top().second),B.pop();
	while(true)
	{
		if(A.empty()) break;
		if(query(-A.top())) break;
		C.push(-A.top());
		add(-A.top(),1);
		A.pop(); 
	}
}
void solve()
{
	n=read();p=read();
	for(LL i=1;i<=n;i++)
	{
		LL x=read();
		B.push(make_pair(-x,i));
	}
	LL now=0;
	while(!(A.empty()&&B.empty()&&C.empty()))
	{
		check(now);
		if(C.empty()&&A.empty()) 
		{
			now=-B.top().first;
			check(now);
		}
		if(!C.empty())
		{
			LL x=C.front();
			while(!B.empty()&&(-B.top().first)<=now+p)
				check(-B.top().first);
			ans[x]=now+p;now+=p;
			add(x,-1);C.pop();
		}
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
}
int main()
{
//	freopen("123.in","r",stdin);
//	freopen("123.out","w",stdout);
	int T=1;
	while(T--)
		solve();
	return 0;
}

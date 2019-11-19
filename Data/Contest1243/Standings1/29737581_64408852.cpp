#include"bits/stdc++.h"

#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?-(x):x) // big bug here if "-x" is not surrounded by "()"
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define din(n) int (n); scanf("%d",&(n)) //handy if the input is right after the definition of a variable
#define din2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define din3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))

using namespace std;

unordered_set<int>st[100005];
set<int>st2;
int cntcomp=0;

void dfs(int u)
{
	st2.erase(u);
	int v=-1;
	while(true)
	{
		auto it=st2.upper_bound(v);
		if(it==st2.end())break;
		v=*it;
		if(st[u].count(v))continue;
		dfs(v);
	}
}
void solve()
{
	int n,m;cin>>n>>m;
	while(m--)
	{
		int u,v;cin>>u>>v;
		st[u].insert(v);
		st[v].insert(u);
	}
	for(int i=1;i<=n;i++)st2.insert(i);
	for(int i=1;i<=n;i++)
	{
		if(st2.count(i))
			cntcomp++,dfs(i);
	}
	cout<<cntcomp-1<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
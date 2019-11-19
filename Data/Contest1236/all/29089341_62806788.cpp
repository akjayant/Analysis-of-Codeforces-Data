#include <bits/stdc++.h>
#define sqr(a) ((a)*(a))
#define rsz resize
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
#define PI 3.1415926535897932384626

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main()
{
	#ifdef REJUNTE
	freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,k,L,U,R,D,cantVisited=0,x,y,nxt;
	cin >> n >> m >> k;
	L=U=0;
	R=m;
	D=n;
	map<int,set<ll>> blocksInR,blocksInC;
	forn(i,k)
	{
		cin >> x >> y;
		x--;
		y--;
		blocksInR[x].insert(y);
		blocksInC[y].insert(x);
	}
	set<ll>::iterator auxit;
	x=y=0;
	int face=0;
	while(L<R && U<D)
	{
		if(blocksInR[x].find(y)!=blocksInR[x].end()) break;
		if(face==0)
		{
			assert(y==L);
			auxit=blocksInR[x].ub(y);
			if(auxit==blocksInR[x].end()) nxt=R-1;
			else nxt=min(R-1,*auxit-1);
			cantVisited+=nxt-y+1;
			y=nxt;
			x++;
			U++;
			R=nxt+1;
		}
		else if(face==1)
		{
			assert(x==U);
			auxit=blocksInC[y].ub(x);
			if(auxit==blocksInC[y].end()) nxt=D-1;
			else nxt=min(D-1,*auxit-1);
			cantVisited+=nxt-x+1;
			x=nxt;
			y--;
			R--;
			D=nxt+1;
		}
		else if(face==2)
		{
			assert(y==R-1);
			auxit=blocksInR[x].lb(y);
			if(auxit==blocksInR[x].begin()) nxt=L;
			else
			{
				auxit--;
				nxt=max(L,*auxit+1);
			}
			cantVisited+=y-nxt+1;
			y=nxt;
			x--;
			D--;
			L=nxt;
		}
		else if(face==3)
		{
			assert(x==D-1);
			auxit=blocksInC[y].lb(x);
			if(auxit==blocksInC[y].begin()) nxt=U;
			else
			{
				auxit--;
				nxt=max(U,*auxit+1);
			}
			cantVisited+=x-nxt+1;
			x=nxt;
			y++;
			L++;
			U=nxt;
		}
		//cout << face << ' ' << cantVisited << '\n';
		face=(face+1)%4;
	}
	if(cantVisited==n*m-k) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
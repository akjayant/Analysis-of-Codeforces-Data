#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cctype>


#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ren(i,a,b) for(int i=a;i>=b;i--)
#define ff first
#define ss second
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<long long int>
#define vii vector<int>
#define gi(n) scanf("%d",&n)
#define gll(n) scanf("%lld",&n)
#define gstr(n) scanf("%s",n)
#define gl(n) cin >> n
#define oi(n) printf("%d",n)
#define oll(n) printf("%lld",n)
#define ostr(n) printf("%s",n)
#define ol(n) cout << n
#define os cout<<" "
#define on cout<<"\n"
#define o2(a,b) cout<<a<<" "<<b
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<vector<ll> > mat;

int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
{
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	string s;
	cin>>s;
	char ans[1005];
	int win=0;
	rep(i,0,n-1)
	{
		if(s[i]=='R')
		{
			if(b)
			{
				win++;
				b--;
				ans[i]='P';
			}
			else
			{
				ans[i]='#';
			}
		}
		else if(s[i]=='P')
		{
			if(c)
			{
				win++;
				c--;
				ans[i]='S';
			}
			else
			{
				ans[i]='#';
			}
		}
		else
		{
			if(a)
			{
				win++;
				a--;
				ans[i]='R';
			}
			else
			{
				ans[i]='#';
			}
		}
	}
	rep(i,0,n-1)
	{
		if(ans[i]=='#')
		{
			if(a)
			{
				a--;
				ans[i]='R';
			}
			else if(b)
			{
				b--;
				ans[i]='P';
			}
			else
			{
				c--;
				ans[i]='S';
			}
		}
		
	}
	if(win>=(n+1)/2)
	{
		ol("YES\n");
		rep(i,0,n-1)ol(ans[i]);
		on;
	}
	else
	{
		ol("NO\n");
	}
}

return 0;
}



#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double
#define f(i,x,n) for(int i=x;i<n;i++)
#define int long long
#define mod 1000000007
#define endl "\n"
#define MAXN 300001 
const int INF = 1e12;
void fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
int32_t main() 
{
	fastio();
	int n,p,w,d;
	cin>>n>>p>>w>>d;
	int aa=p/w,bb=p/d;
	int x,y,z,cc=1000001;
	for(int i=0;i<min(aa+1,cc);i++)
	{
		int tp=(aa-i);
		int zz=p-tp*w;
		if(zz%d==0)
		{
			x=tp;
			y=zz/d;
			break;
		}
	}
	if(x+y<=n)
		cout<<x<<" "<<y<<" "<<n-(x+y);
	else
		cout<<-1;
}
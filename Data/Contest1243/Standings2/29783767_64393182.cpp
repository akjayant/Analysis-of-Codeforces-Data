#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define forout(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pii pair<int,int>
#define fi first
#define se second
#define sz(s) (int)(s.size())
#define pb push_back
#define int long long
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define bit(x,i) ((x>>i)&1)
#define batbit(x,i) (x|(1ll<<i))
#define tatbit(x,i) (x&~(1ll<<i))
#define task "1243A"
using namespace std;
const int N=1e4+1;
int x[N];
int kq,fre[N];
vector<int >ke[N];
void dfs(int u)
{
    fre[u]=1;
    forv(v,ke[u])
    {
        if(fre[v]==0) dfs(v);
    }
}
main()
{
	///freopen(task".inp","r",stdin);
	///freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	forinc(i,1,5) ke[i].push_back(i+1);
	dfs(1);
	int t;
	cin>>t;
	while(t--)
    {
        kq=1;
        int n;
        cin>>n;
        forinc(i,1,n) cin>>x[i];
        sort(x+1,x+n+1);
        forinc(i,1,n)
        {
            int b=min(n-i+1,x[i]);
            kq=max(kq,b);
        }
        cout<<kq<<"\n";
    }
}

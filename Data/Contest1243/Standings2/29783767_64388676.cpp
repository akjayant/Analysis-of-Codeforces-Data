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
#define task "1243B1"
using namespace std;
const int N=1e4+5;
int z[N];
main()
{
	///freopen(task".inp","r",stdin);
	///freopen(task".out","w",stdout);
	int k;
	cin>>k;
	forinc(i,1,k)
	{
	    memset(z,0,sizeof z);
	    int n;
	    cin>>n;
	    string s,t;
	    cin>>s>>t;
	    s=' '+s;
	    t=' '+t;
	    int cnt=0;
	    forinc(i,1,n)
	    {
	        if(s[i]!=t[i])
            {
                z[++cnt]=i;
            }
	    }
	    if(cnt>2||cnt==1)
        {
            cout<<"NO\n";
            continue;
        }
        else if(cnt==0)
        {
            cout<<"NO\n";
            continue;
        }
        else if(cnt==2)
        {
            if(s[z[1]]==s[z[2]]&&t[z[1]]==t[z[2]]) cout<<"YES\n";
            else cout<<"NO\n";
        }

	}
}

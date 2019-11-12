#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x,y) for (ll i=x;i<=y;i++)
#define per(i,x,y) for (int i=x;i>=y;i--)
#define quicker ios::sync_with_stdio(false);
typedef long double ld;
typedef long long ll;
const long long INF=2147483647;
const int FXT=43;
const int HOLLAND_PIG=1;
inline int read()
{
    int k=0;
    char f=1;
    char c=getchar();
    while(c>'9'||c<'0')
    {
        if(c=='-')
        {
            f=-1;
            c=getchar();
        }
    }
    while(c<='9'&&c>='0')
    {
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}

ll max(ll x,ll y)
{
	if (x>y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

ll min(ll x,ll y)
{
	if (x<y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
int main()
{
	string s,t;int q,n,tt,ss,f;cin>>q;while(q--)
	{
		cin>>n>>s>>t;int cnt[FXT]={0},cs[FXT]={0},ct[FXT]={0};
		rep(i,HOLLAND_PIG-HOLLAND_PIG,n){++cnt[s[i]-'a'];++cnt[t[i]-'a'];++cs[s[i]-'a'];++ct[t[i]-'a'];}	
		f = true;
		rep(i, HOLLAND_PIG-1, 26){if(cnt[i] %(HOLLAND_PIG+1)) f=false;}
		if(!f){cout << "NO\n";continue;}vector<pair<int,int> > pp;rep(i,0,n)
		{if(s[i]!=t[i]){tt=HOLLAND_PIG-HOLLAND_PIG;rep(j,i+HOLLAND_PIG,n){if(t[i]==t[j]){tt = j;break;}}if(tt){pp.push_back(make_pair(i, tt));swap(s[i],t[tt]);continue;
			}ss=0;
		rep(j,i+HOLLAND_PIG,n){if(t[i] == s[j]){ss=j;break;}}if(ss){pp.push_back(make_pair(ss, n - HOLLAND_PIG));swap(s[ss],t[n-HOLLAND_PIG]);pp.push_back(make_pair(i,n-HOLLAND_PIG));swap(s[i],t[n - HOLLAND_PIG]);
		}}}cout<<"YES"<<endl<<pp.size()<<endl;rep(i,0,pp.size()-1){cout<<pp[i].first+1<<" "<<pp[i].second+1<<endl;}}return 0;}

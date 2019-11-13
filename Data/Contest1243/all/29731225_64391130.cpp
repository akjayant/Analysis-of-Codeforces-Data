#include<bits/stdc++.h>
using namespace std;

#define IO ios::sync_with_stdio(false);cin.tie(0)
#define _rep(i,a,b) for(int i = (a);i<=(b);++i)
#define _for(i,a,b) for(int i = (a);i<(b);++i)
#define _dep(i,a,b) for(int i = (a);i>=(b);--i)
#define pb push_back
#define fr first
#define sc second
#define all(x) (x).begin(),(x).end()


typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
typedef vector<int> vi;

const int maxn = 300050;
const LL mod = 1e9+7;
		

int seq[maxn];
int n;
string s,t;


void solve()
{
	vector<int> pos;
	int ok=0;
	_for(i,0,n) if(s[i]!=t[i])pos.pb(i);
	if(pos.empty())
	{
		cout<<"Yes\n";return;
	}
	vector<pii> ans;
	_for(i,0,n)
	{
		if(s[i]==t[i])continue;
		int tmp = -1;
		int kd = -1;
		_for(j,i+1,n)
		{
			if(s[j]==t[j])continue;
			if(t[i]==t[j])
			{
				kd = 1;
				tmp = j;
				break;
			}
			if(s[i]==s[j])
			{
				kd = 0;
				tmp = j;
				break;
			}
			if(s[i]==t[j])
			{
				swap(t[j],s[j]);
				kd = 0;
				tmp = j;
				ans.pb({j,j});
				break;
			}
			if(t[i]==s[j])
			{
				kd = 1;
				tmp = j;
				swap(t[j],s[j]);
				ans.pb({j,j});
				break;
			}
		}
		if(kd==-1)
		{
			cout<<"No\n";
			return;	
		}
		if(kd==1)
		{
			swap(s[i],t[tmp]);
			ans.pb({i,tmp});
		}
		else{
			swap(s[tmp],t[i]);
			ans.pb({tmp,i});
		}
	}
	if(ans.size()>2*n)
	{
		cout<<"No\n";
		return;
	}
	cout<<"Yes\n";
	cout<<ans.size()<<endl;
	for(auto x:ans)
	{
		cout<<x.fr+1<<" "<<x.sc+1<<endl;
	}
}

int main(void)
{
	IO;
	int q;
	cin>>q;
	while(q--)
	{
		cin>>n;
		cin>>s>>t;
		solve();
	}
	return 0;
}












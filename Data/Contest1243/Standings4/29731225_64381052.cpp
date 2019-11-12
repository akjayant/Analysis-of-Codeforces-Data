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


int main(void)
{
	IO;
	int q;
	cin>>q;
	while(q--)
	{
		string s,t;
		cin>>n;
		cin>>s>>t;
		int dif=0;
		vector<int> d;
		_for(i,0,n)
		{
			if(s[i]==t[i])continue;
			dif++;
			d.pb(i);
		}
		if(dif>=3){
			cout<<"No\n";
			continue;
		}
		int ok=0;
		for(auto x:d)
		{
			for(auto y:d)
			{
				string ss,tt;
				ss = s,tt = t;
				swap(ss[x],tt[y]);
				if(ss==tt)ok=1;
			}
		}
		if(ok||dif==0) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}












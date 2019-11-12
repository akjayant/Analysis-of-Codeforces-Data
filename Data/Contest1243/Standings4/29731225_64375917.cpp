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


int judge(int x)
{
	int cnt=0;
	_rep(i,1,n) if(seq[i]>=x)cnt++;
	if(x<=cnt)return 1;
	else return 0;
}

int main(void)
{
	IO;
	int q;cin>>q;
	while(q--)
	{
		int ma = -1;
		cin>>n;
		_rep(i,1,n)
		{
			cin>>seq[i];
			ma = max(ma,seq[i]);
		}
		int ans=1;
		_rep(i,1,ma)
		{
			if(judge(i))ans = i;
		}
		cout<<ans<<endl;
	}
	return 0;
}












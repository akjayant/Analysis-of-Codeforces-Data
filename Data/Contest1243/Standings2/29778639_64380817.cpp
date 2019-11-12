#include<bits/stdc++.h>
#define dd(x) cout<<#x<<" = "<<x<<" "
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define sz(x) int(x.size())
#define All(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef priority_queue<int> BQ;
typedef priority_queue<int,vector<int>,greater<int> > SQ;
const int maxn=1e5+10,mod=1e9+7,INF=0x3f3f3f3f;
char s[maxn],t[maxn];
int main()
{
	int T;
	cin>>T;
	while (T--){
		int n;
		scanf("%d%s%s",&n,s,t);
		vector<int> v;
		for (int i=0;i<n;++i)
			if (s[i]!=t[i])
				v.pb(i);
		if (sz(v)!=2)
			printf("No\n");
		else{
			int i=v[0],j=v[1];
			if (s[i]==s[j]&&t[i]==t[j])
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}

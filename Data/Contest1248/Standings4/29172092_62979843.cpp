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

int main()
{
	int T;
	cin>>T;
	while (T--){
		int cnt1[2]={0};
		int cnt2[2]={0};
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;++i){
			int x;
			scanf("%d",&x);
			cnt1[x&1]++;
		}
		int m;
		scanf("%d",&m);
		for (int i=1;i<=m;++i){
			int x;
			scanf("%d",&x);
			cnt2[x&1]++;
		}
		printf("%lld\n",ll(cnt1[0])*cnt2[0]+ll(cnt1[1])*cnt2[1]);
	}
	return 0;
}

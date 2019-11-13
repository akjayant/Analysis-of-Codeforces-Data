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
int a[maxn]; 
int main()
{
	int T;
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		for (int i=1;i<=n;++i)
			cin>>a[i];
		sort(a+1,a+1+n);
		int ans=0;
		for (int i=n;i;--i)
			ans=max(ans,min(n-i+1,a[i]));
		cout<<ans<<"\n";
	}
	return 0;
}

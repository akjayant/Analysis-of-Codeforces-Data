#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pb push_back
#define pf pop_front
#define mp make_pair
#define mod 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mat vector<vector<int>>
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define fo(i,n) for(int i=0;i<n;i++)
#define inp(a) int a;cin>>a;
#define inpa(a,n)vector<int> a(n);fo(i,n)cin>>a[i];
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
using namespace std;
#define int ll


auto max(auto a){auto ans=a[0];for(auto i:a)if(i>ans)ans=i;return ans;}
auto min(auto a){auto ans=a[0];for(auto i:a)if(i<ans)ans=i;return ans;}
void print(auto a){for(auto i:a)cerr<<i<<' ';cerr<<'\n';}



int calc(int n,int m)
{
	if(m==1)
		return 1;
	m--;
	int dp1[m+1]={0},dp2[m+1]={0};
	dp1[0]=1;
	for(int i=1;i<=m;i++)
	{
		dp1[i]=(dp1[i-1]+dp2[i-1])%mod;
		dp2[i]=dp1[i-1];
	}
	return (dp1[m]+dp2[m])%mod;
}


signed main()
{
	fio
	inp(n) inp(m)
	// cout<<calc(n,m)<<','<<calc(m,n)<<'\n';
	int ans=(calc(n,m)+calc(m,n)-1+mod)%mod;
	cout<<(ans*2)%mod<<'\n';
	printclock;
}
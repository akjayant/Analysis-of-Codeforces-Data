#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000000000001LL
#define inf 1000000000
#define pii pair<int,int>
#define pis pair<int,string>
#define pil pair<int,ll>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define pdb pair<double,bool>
#define pdi pair<double,int>
#define pid pair<int,double>
#define pidd pair<int,pdd>
#define pddi pair<pdd,int>
#define pli pair<ll,int>
#define pdbi pair<pdb,int>
#define piii pair<int,pii>
#define fi first
#define se second
#define mod 1000000007LL
#define start (1<<20)

int n,m;
ll dp[111111];
ll output;
int main()
{
	//ios_base::sync_with_stdio(false); cout.tie(NULL);cin.tie(NULL);
	//scanf("%d",&T);
	//cin>>T;
	//while(T--)
	//{
	//}
	//FILE *ifp;
  	//ifp = fopen("output.txt","w");
  	//ifp = stdin;
  	//fscanf(ifp,"%d",&T);
	//fclose(ifp);
	scanf("%d %d",&n,&m);

	dp[1] = 1LL;
	dp[2] = 2LL;
	if(n > m)
		swap(n,m);
	int k = max(n,m);
	for(int i = 3 ; i <= k ; i++)
	{
		dp[i] = dp[i-1]+ dp[i-2];
		dp[i] %= mod;
	}
	output = dp[1];
	if(n == 1)
		output = 0LL;
	for(int i = 1 ; i < n - 1 ; i++)
	{
		output += dp[i];
		output %= mod;
	}
	output += dp[m];
	output *= 2LL;
	output %= mod;
	printf("%lld",output);

	return 0;
}

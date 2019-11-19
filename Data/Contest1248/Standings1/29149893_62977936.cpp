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

int T;
int n;
int odd[2];
int even[2];
int main()
{
	//ios_base::sync_with_stdio(false); cout.tie(NULL);cin.tie(NULL);
	scanf("%d",&T);
	//cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		even[0] = 0;
		even[1] = 0;
		odd[0] = 0;
		odd[1] = 0;
		int t;
		for(int i= 0 ; i < n ; i++)
		{
			scanf("%d",&t);
			if(t % 2== 0)
				even[0]++;
			else
				odd[0]++;
		}
		scanf("%d",&n);
		for(int i= 0 ; i < n ; i++)
		{
			scanf("%d",&t);
			if(t % 2== 0)
				even[1]++;
			else
				odd[1]++;
		}
		printf("%lld\n",(ll)even[0] * even[1] + (ll)odd[0] * odd[1]);
	}
	//FILE *ifp;
  	//ifp = fopen("output.txt","w");
  	//ifp = stdin;
  	//fscanf(ifp,"%d",&T);
	//fclose(ifp);

	return 0;
}

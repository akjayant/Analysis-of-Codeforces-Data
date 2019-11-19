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

int n;
ll a[111111];
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

	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
		scanf("%lld",&a[i]);
	sort(a,a+n);
	ll val1=0LL,val2=0LL;
	int nh = n/2;
	for(int i = 0 ; i < nh ; i++)
		val1+=a[i];
	for(int i = nh ; i < n ; i++)
		val2+=a[i];
	printf("%lld",val1*val1+val2*val2);

	return 0;
}

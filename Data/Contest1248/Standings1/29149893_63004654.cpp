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
string s;
int a,b;
int ans;
int ans1,ans2;
int k[311111];
int mink;
void f(int x,int y,bool flag = true)
{
	int output = 0;
 
 	if(flag)
	{
		s[x] ^= s[y];
		s[y] ^= s[x];
		s[x] ^= s[y];
	}
 
	int a =0;
	mink = 1;
	int idx = -1;
	for(int i = 0  ; i < n ; i++)
	{
		if(s[i] == '(')
		{
			a++;
		}
		else
		{
			a--;
		}
		k[i] = a;
		if(k[i] < mink)
		{
			mink = k[i];
			idx = i;
			output = 1;
		}
		else if(k[i] == mink)
		{
			output++;
		}
	}
 
 	if(flag)
	{
		s[x] ^= s[y];
		s[y] ^= s[x];
		s[x] ^= s[y];
	}
 
	if( output > ans)
	{
		ans = output;
		ans1 = x;
		ans2 = y;
	}
}
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
	cin>>n>>s;
	for(int i = 0 ;  i < n;i++)
	{
		if(s[i] == '(')
			a++;
		else
			b++;
	}
	if(a!=b)
	{
		printf("0\n1 1");
		return 0;
	}
	if(n == 2)
	{
		printf("1\n1 1");
		return 0;
	}
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = i+1 ; j < n ; j++)
		{
			if(s[i] == s[j])
				continue;
			else
			{
				f(i,j);
			}
		}
	}
	f(0,0,false);
	printf("%d\n%d %d",ans,ans1+1,ans2+1);
	return 0;
}

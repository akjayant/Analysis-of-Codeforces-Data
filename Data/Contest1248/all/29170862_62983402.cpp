#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<string>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(a,b,c) for(int a=b;a<c;a++)
#define repp(a,b,c) for(int a=b;a<=c;a++)
#define pb push_back
const int inf=0x3f3f3f3f;
ll vis1[2],vis2[2];
int main()
{
	
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		mem(vis1,0);
		mem(vis2,0);
		rep(i,0,n)
		{
			ll a;
			cin>>a;
			vis1[a%2]++;
		}
		int m;
		cin>>m;
		rep(i,0,m)
		{
			ll a;
			cin>>a;
			vis2[a%2]++;
		}
		cout<<vis1[0]*vis2[0]+vis1[1]*vis2[1]<<'\n';
	}
}

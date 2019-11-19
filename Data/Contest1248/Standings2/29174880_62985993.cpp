#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

int lo[101010];
int lx,ly;
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>lo[i];
	sort(lo+1,lo+n+1);
//	cout<<lo[n]<<endl;
	int pl=n;
	long long dis=0;
	if(n==1)
	{
		cout<<1ll*lo[1]*lo[1]<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		lx+=lo[i];
		ly+=lo[pl];
		pl--;
		if(i+1==pl)
		{
			ly+=lo[pl];
			break;
		}
		else if(i+1>pl)
			break;
	}
	dis=1ll*lx*lx+1ll*ly*ly;
	cout<<dis<<endl;
	return 0;
}
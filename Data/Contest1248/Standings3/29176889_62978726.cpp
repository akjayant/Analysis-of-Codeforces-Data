#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include <iostream>
#define LL long long
using namespace std;

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while (T--)
	{
		int n; scanf("%d",&n);
		LL tot=0,tot1=0;
		for (int i=1; i<=n; i++)
		{
			int x; scanf("%d",&x);
			if (x%2) tot++;
			else tot1++;
		}
		int m; scanf("%d",&m);
		LL _tot=0,_tot1=0;
		for (int i=1; i<=m; i++)
		{
			int x; scanf("%d",&x);
			if (x%2) _tot++;
			else _tot1++;
		}
		cout<<tot*_tot+_tot1*tot1<<endl;
	}
	return 0;
}
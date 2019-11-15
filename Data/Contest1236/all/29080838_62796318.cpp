#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 1LL<<60
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=310;
const LL mod=1e9+7;
int ans[N][N];
int n;
//void get1(int x)
//{
//	for(int i=1;i<=n;i++)
//		ans[i].push_back();
//}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=n;i>=1;i--)
	{
		if(i&1)
			for(int j=1,fir=n*(n-i+1);j<=n;j++,fir--)
				ans[j][i]=fir;
		else
			for(int j=n,fir=n*(n-i+1);j>=1;j--,fir--)
				ans[j][i]=fir;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<ans[i][j]<<' ';
		cout<<endl;
	}
		
}
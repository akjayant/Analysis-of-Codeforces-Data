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
const int N=1010;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(b==0)
		{
			cout<<0<<'\n';
			continue;
		}
		int gb=min(b,c/2);
		b-=gb;
		int ga=min(a,b/2);
		cout<<3*(ga+gb)<<'\n';
	}
}
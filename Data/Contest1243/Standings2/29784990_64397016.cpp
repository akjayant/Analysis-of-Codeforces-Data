#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<cmath>
#define int long long
using namespace std;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,ouo,cnt=0,qwq=0;
	cin>>n;
	if(n==1)
		cnt=10;
	ouo=n;
	int i;
	for(i=2;i<=sqrt(ouo);i++)
	{
		if(n%i==0)
		{
			if(!cnt)
				qwq=i;
			cnt++;
			while(n%i==0)
			{
				n/=i;
			}
		}
	}
	if(n>1)
	{
		cnt++;
		qwq=n;
	}
	if(cnt>1)
	{
		cout<<"1\n";
	}
	else
	{
		cout<<qwq<<"\n";
	}
	
	return 0;
}


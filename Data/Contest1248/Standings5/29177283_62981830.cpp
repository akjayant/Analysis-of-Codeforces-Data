#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1e5+10;
int a[N],b[N];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long cnt1=0,cnt2=0,cnt11=0,cnt22=0;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			if(a[i]&1) cnt1++; 
			else cnt2++;
		}
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>b[i];
			if(b[i]&1) cnt11++;
			else cnt22++;
		}
		cout<<(cnt11*cnt1+cnt22*cnt2)<<endl;
	}
	return 0;
}
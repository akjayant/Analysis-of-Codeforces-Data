#include <bits/stdc++.h>

using namespace std;
#define fr(i,x,y) for(int i=x;i<y;i++)
#define int long long
const int N=1e6,INF=1e18;
int mas[N];
 main()
{
	int n,k;
	cin>>n>>k;
	fr(i,0,n)
	{
		cin>>mas[i];
	}
	sort(mas,mas+n);
	int i=0,j=n-1;
	while(i<j)
	{
		while(mas[i]==mas[i+1] && i<j)i++;
		while(mas[j]==mas[j-1] && i<j)j--;
		if(k<min(i+1,n-j))break;
		if(i+1<n-j)
		{
			int q=min((mas[i+1]-mas[i]),k/(i+1));
			k-=q*(i+1);
			mas[i]+=q;
		}
		else
		{
			int q=min((mas[j]-mas[j-1]),k/(n-j));
			k-=q*(n-j);
			mas[j]-=q;
		}
	}
	cout<<mas[j]-mas[i];
}
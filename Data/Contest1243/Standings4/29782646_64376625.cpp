#include<bits/stdc++.h>
using namespace std;

bool sort_by(int a, int b)
{
	return a>b;
}

int main()
{
	int T;
	cin>>T;
	for(int t=0; t<T; t++)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		sort(a, a+n, sort_by);
		int ans=1;	
		for(int i=0; i<n; i++)
		{
			if(a[i]>=i+1)
				ans=i+1;
			else
				break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
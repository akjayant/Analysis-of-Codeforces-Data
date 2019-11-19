#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
	int t=0;	
	cin >> t;
	while (t--){
		int n=0,m=0;
		int arr1[2]={}, arr2[2]={};
		cin >> n;
		for (int i=0; i<n; i++)
		{
			int a=0;
			cin >> a;
			arr1[a%2]++;		
		}	
		cin >> m;
		int res=0;
		for (int i=0; i<m; i++)
		{
			int a=0;
			cin >> a;
			res+=arr1[a%2];
		}	
		cout << res<<endl;
	}
}
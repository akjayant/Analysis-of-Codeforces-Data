#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<iomanip>
using namespace std;

int arr[100010];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,i;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		for(i=0;i<n;i++)
		{
			if(arr[i]>=n-i)
			{
				cout<<n-i<<'\n';
				break;
			}
		}
	}
	
	return 0;
}

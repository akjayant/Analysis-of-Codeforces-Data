#include <bits/stdc++.h>
#define int long long
#define pet pair<int,int>
#define one first
#define two second
using namespace std;

void solve()
{
	int n;
	cin >> n;
	
	int arr[n];
	
	for(int i=0;i<n;i++)
	cin >> arr[i];
	
	sort(arr,arr+n);
	int s1=0;
	
	for(int i=0;i<n/2;i++)
	s1+=arr[i];
	
	int s2=0;
	
	for(int i=n/2;i<n;i++)
	s2+=arr[i];
	
	cout << s1*s1+s2*s2 << endl;
}

main()
{
	int t=1;
	//cin >> t;
	
	while(t--)
	solve();
}


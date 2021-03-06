#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+10;

int arr[MAX];

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i=0;i<n;++i)
		cin >> arr[i];

	sort(arr, arr + n);

	long long x=0, y=0;
	for(int i=0;i<n/2;++i)
		x += arr[i];
	for(int i=n/2;i<=n;++i)
		y += arr[i];
	
	cout << x*x + y*y << '\n';

	return 0;
}
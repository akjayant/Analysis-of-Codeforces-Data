#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l, r;
	int arr[100005];
	long long x, y;
	cin>>n;
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	sort(arr,arr+n);
	l = 0;
	r = n-1;
	x = 0;
	y = 0;
	while(l < r) {
		x+=arr[l];
		y+=arr[r];
		l++;
		r--;
	}
	if(l==r) {
		y+=arr[r];
	}
	cout<<y*y+x*x<<endl;
	
}

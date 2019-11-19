#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,i;
	long long a[100005],x=0,y=0,sum=0;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	for(i=0;i<n/2;i++){
		x+=a[i];
	}
	y=sum-x;
	cout << x*x+y*y << endl;
	return 0;
}
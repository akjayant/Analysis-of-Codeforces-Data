#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	ll x=0,y=0;
	for(int i=0;i<n/2;i++)
		x+=a[i];
	for(int i=n/2;i<n;i++)
		y+=a[i];
	cout << x*x+y*y << endl;
}
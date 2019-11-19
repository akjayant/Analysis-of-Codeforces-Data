#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];

int main(){
	int n; cin >> n;
	for(int i = 1 ; i <= n ; i++)cin >> a[i];
	sort(a+1,a+1+n);
	long long l = 0, r = 0;

	for(int i = 1 ; i <= n / 2 ; i++)l += a[i];
	for(int i = (n / 2) + 1 ; i <= n ; i++)r += a[i];


	cout << l*l + r*r <<endl;

}
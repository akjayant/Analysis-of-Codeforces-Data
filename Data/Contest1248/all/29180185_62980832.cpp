#include <bits/stdc++.h>
using namespace std;

int n ,i , l[100005];
long long x , y;

int main()
{
	cin >> n;
	for(i = 1 ; i <= n ; i ++ ) cin >> l[i];
	sort(l + 1 , l + 1 + n);
	for(i = 1 ; i <= n/2 ; i ++) x += l[i];
	for( ; i <= n ; i ++) y += l[i];
	cout << x*x + y*y << endl;
} 

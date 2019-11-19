#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 100;
int val[maxn],n,mid;
long long a,b,ans;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> val[i];
	sort(val + 1,val + 1 + n);
	mid = n >> 1;
	for(int i = 1;i <= mid;i++)
		a += val[i];
	for(int i = mid + 1;i <= n;i++)
		b += val[i];
	ans = a * a + b * b;
	cout << ans << endl;
	return 0;
} 
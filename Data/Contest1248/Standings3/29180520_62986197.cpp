#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[100005], sum = 0, sum1 = 0, sum2;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
		cin>>a[i];
		sum += a[i];
	}
    sort(a+1, a+n+1);
    for(int i = n; i >= n - (n+1) / 2 + 1; i--)
    	sum1 += a[i];
    sum2 = sum - sum1;
    cout<<sum1 * sum1 + sum2 * sum2<<endl;
    return 0;
}
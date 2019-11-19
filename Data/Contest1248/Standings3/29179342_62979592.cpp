#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long x[100005];
int main (){
	long long n, i, sum1=0, sum2=0;
	cin >> n;
	for (i=1; i<=n; i++)
        cin >> x[i];
    sort (x+1, x+n+1);
    for (i=1; i<=n/2; i++)
        sum1 += x[i];
    for (i; i<=n; i++)
        sum2 += x[i];
    cout << (long long)(sum1) * sum1 + (long long)(sum2) * sum2;
	return 0;
}

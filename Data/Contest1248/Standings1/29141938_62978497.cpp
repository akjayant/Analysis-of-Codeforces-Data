#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 100005;
int n,a[MAXN];

int main()
{
    cin >> n;
    for(int i = 1; i<=n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    ll x = 0, y = 0;
	for(int i = 1; i<=n/2; i++)
	    x += a[i];
	for(int i = n/2+1; i<=n; i++)
	    y += a[i];
	cout << x*x+y*y << endl; 
	return 0;
}

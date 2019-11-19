#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define ll long long
#define ull unsigned long long
#define sscc ios::sync_with_stdio(false);cin.tie(0);
#define ms(a) memset(a,0,sizeof(a))
#define mss(a) memset(a,-1,sizeof(a))
#define msi(a) memset(a,inf,sizeof(a))
using namespace std;

const int N=100000+5;
ll a[N];

int main()
{
	sscc;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	ll x=0,y=0;
	for(int i=1;i<=n/2;i++)	x+=a[i];
	for(int i=n/2+1;i<=n;i++)	y+=a[i];
	cout<<(x*x+y*y)<<endl;
	return 0;
}


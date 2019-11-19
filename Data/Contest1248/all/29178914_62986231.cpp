/*input
4
1 9 2 2

*/
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 100002

using namespace std;
int main()
{
	ll n;
	 cin >> n;
	 // watch(n);
	 ll a[n];
	 for (ll i = 0; i < n; ++i)
	 {
	 	cin  >> a[i];
	 }
	 sort(a,a+n);
	 ll m = n/2;
	 // watch(m);
	 ll sum1=0,sum2=0;
	 for (ll i = m; i < n; ++i)
	 {
	 	sum1+=a[i];
	 }
	 for (ll i = 0; i < m; ++i)
	 {
	 	sum2+=a[i];
	 }
	 cout << sum1*sum1 + sum2*sum2 << endl;
	}
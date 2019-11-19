#include<bits/stdc++.h>
#define pb   push_back
#define mp   make_pair
#define f    first
#define s    second
#define ll   long long
#define vi vector< int >
#define vl vector< ll >
#define rep(i,j,n)  for(int (i) = (j); i < n; i++)
#define MAX(a, b)     ((a) > (b) ? (a) : (b))
#define MIN(a, b)     ((a) < (b) ? (a) : (b))
#define all(v) v.begin(), v.end()
#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define T() int tt; cin>>tt; while(tt--)
#define Max  INT_MAX
#define Min  INT_MIN
#define mod  1000000007
#define N 1000099
using namespace std;

ll a[100008];

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a+0, a+n);
	int i=0;
	ll x=0,y=0;
	for(i=0;i<n/2;i++) x+=a[i];
	for(;i<n;i++) y+=a[i];
	ll ans = x*x + y*y;
	cout<<ans<<"\n";
}


